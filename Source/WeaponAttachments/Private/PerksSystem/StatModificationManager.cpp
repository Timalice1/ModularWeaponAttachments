#include "PerksSystem/StatModificationManager.h"
#include "PerksSystem/ModifiableInterface.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogModificationsManager, Log, All);

UStatModificationManager::UStatModificationManager()
{
    PrimaryComponentTick.bCanEverTick = false;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UStatModificationManager::BeginPlay()
{
    Super::BeginPlay();
    if (!GetOwner()->GetClass()->ImplementsInterface(UModifiableInterface::StaticClass()))
    {
        UE_LOG(LogModificationsManager, Error,
               TEXT("%s:%s - Owner does not implement IModifiableInterface, but ModificationsManager require it."),
               *GetOwner()->GetName(), *GetName());
        return;
    }
    IModifiableInterface::Execute_MapDefaultProperties(GetOwner(), _parametersCache, _assetsCache);
    if (_parametersCache.IsEmpty() || _assetsCache.IsEmpty())
    {
        UE_LOG(LogModificationsManager, Warning,
               TEXT("%s: Cache maps are empty. Concider using IModifiableInterface::MapDefaultProperties for caching all target parameters."),
               *GetOwner()->GetName());
        return;
    }

    _finalParameters = _parametersCache;
    _finalAssets = _assetsCache;
}

void UStatModificationManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    RemoveAllModificators();
}

void UStatModificationManager::RecalculateModifications()
{
    EvaluateParameters();
    OverrideAssets();
}

void UStatModificationManager::EvaluateParameters()
{
    if (_parametersCache.IsEmpty() || _dirtyParameters.IsEmpty())
        return;

    for (const FGameplayTag &dirtyParam : _dirtyParameters)
    {
        if (const float *cachedParam = _parametersCache.Find(dirtyParam))
        {
            bool isPercent = false;
            bool bClamp = false;
            float ClampMin = 0.f;
            float ClampMax = 0.f;

            float finalValue = *cachedParam;
            float percentageValue = 0.f;
            for (const TPair<FName, FModifier> &activeModifier : _activeModifiers)
            {
                /*Find target modificator for current parameter, and modify target parameter*/
                if (const FParamModifier *targetModificator = activeModifier.Value.ParametersModificators.Find(dirtyParam))
                {
                    if (targetModificator->ModificationType == EModifierOp::Percent)
                    { // Stack percentage value, cache modificator params
                        isPercent = true;
                        bClamp = targetModificator->bClampValue;
                        ClampMin = targetModificator->Min;
                        ClampMax = targetModificator->Max;
                        percentageValue += targetModificator->Value;
                    }
                    if (targetModificator->ModificationType == EModifierOp::Override)
                        finalValue = targetModificator->Value;
                }
                else
                    UE_LOG(LogModificationsManager, Warning, TEXT("Modificator for parameter %s did not found"), *dirtyParam.ToString());
            }
            if (isPercent)
            {
                finalValue *= 1 + (percentageValue / 100);
                if (bClamp)
                    finalValue = FMath::Clamp(finalValue, ClampMin, ClampMax);
            }

            _finalParameters.Add(dirtyParam, finalValue);

            /*Send message to the owner about parameter has been modified*/
            OnParameterModified.Broadcast(dirtyParam, finalValue);
        }
        else
            UE_LOG(LogModificationsManager, Warning, TEXT("Parameter %s did not found in cache"), *dirtyParam.ToString());
    }

    /* Clean up dirty parameters*/
    _dirtyParameters.Empty();
}

void UStatModificationManager::OverrideAssets()
{
    if (_assetsCache.IsEmpty() || _dirtyAssets.IsEmpty())
        return;

    for (const FGameplayTag &dirtyAsset : _dirtyAssets)
    {
        if (UObject **cachedAsset = _assetsCache.Find(dirtyAsset))
        {
            UObject *finalAsset = *cachedAsset;
            for (const TPair<FName, FModifier> &activeModifier : _activeModifiers)
            {
                if (const TSoftObjectPtr<UObject> *targetAssetPtr = activeModifier.Value.AssetsOverrides.Find(dirtyAsset))
                    finalAsset = targetAssetPtr->LoadSynchronous();
                else
                    UE_LOG(LogModificationsManager, Warning, TEXT("Modificator for parameter %s did not found"), *dirtyAsset.ToString());
            }
            _finalAssets.Add(dirtyAsset, finalAsset);
            OnAssetModified.Broadcast(dirtyAsset, finalAsset);
        }
        else
            UE_LOG(LogModificationsManager, Warning, TEXT("Asset parameter %s did not found in cache"), *dirtyAsset.ToString());
    }

    /* Clean up dirty assets*/
    _dirtyAssets.Empty();
}

void UStatModificationManager::ApplyModificator(const FName &ModificatorID, const FModifier &inModifier)
{
    for (const TPair<FGameplayTag, FParamModifier> &paramModificator : inModifier.ParametersModificators)
    {
        if (!_parametersCache.Contains(paramModificator.Key))
            UE_LOG(LogModificationsManager, Error, TEXT("ApplyModificator: Parameter modificator %s has parameter %s that not found in cache."),
                   *ModificatorID.ToString(), *paramModificator.Key.ToString());
    }
    for (const TPair<FGameplayTag, TSoftObjectPtr<UObject>> &assetModificator : inModifier.AssetsOverrides)
    {
        if (!_assetsCache.Contains(assetModificator.Key))
            UE_LOG(LogModificationsManager, Error, TEXT("ApplyModificator: Asset modificator %s has parameter %s that not found in cache."),
                   *ModificatorID.ToString(), *assetModificator.Key.ToString());
    }

    _activeModifiers.Add(ModificatorID, inModifier);
    MarkAsDirty(inModifier);
    RecalculateModifications();
}

void UStatModificationManager::RemoveModificator(const FName &ModificatorID)
{
    if (const FModifier *modifier = _activeModifiers.Find(ModificatorID))
    {
        MarkAsDirty(*modifier);
        _activeModifiers.Remove(ModificatorID);
        RecalculateModifications();
    }
    else
        UE_LOG(LogModificationsManager, Warning,
               TEXT("%s %s::RemoveModificator: active modifier with id [%s] was not found"),
               *GetOwner()->GetName(), *GetName(), *ModificatorID.ToString());
}

void UStatModificationManager::RemoveAllModificators()
{
    for (const TPair<FName, FModifier> &activeModifier : _activeModifiers)
        RemoveModificator(activeModifier.Key);
}

void UStatModificationManager::MarkAsDirty(const FModifier &modifier)
{
    for (const TPair<FGameplayTag, FParamModifier> &ParamModifier : modifier.ParametersModificators)
        _dirtyParameters.Add(ParamModifier.Key);
    for (const TPair<FGameplayTag, TSoftObjectPtr<UObject>> &AssetModifier : modifier.AssetsOverrides)
        _dirtyAssets.Add(AssetModifier.Key);
}

float UStatModificationManager::GetModifiedParamByTag(const FGameplayTag &Tag)
{
    if (_finalParameters.IsEmpty())
    {
        UE_LOG(LogModificationsManager, Warning, TEXT("Modified parameters cache is empty"));
        return 0.f;
    }

    if (const float *finalParam = _finalParameters.Find(Tag))
        return *finalParam;

    UE_LOG(LogModificationsManager, Warning, TEXT("FinalModifiedParameters: parameter [%s] not found"),
           *Tag.ToString());
    return 0.f;
}

UObject *UStatModificationManager::GetModifiedAssetByTag(const FGameplayTag &Tag)
{
    if (_finalAssets.IsEmpty())
    {
        UE_LOG(LogModificationsManager, Warning, TEXT("Final assets cache is empty"));
        return nullptr;
    }
    if (!_finalAssets.Contains(Tag))
    {
        UE_LOG(LogModificationsManager, Warning, TEXT("Assets cache did not contain parameter [%s]"), *Tag.ToString());
        return nullptr;
    }

    return *_finalAssets.Find(Tag);
}