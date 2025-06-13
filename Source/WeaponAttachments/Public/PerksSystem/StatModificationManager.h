#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "PerksSystem/StatModifier.h"

#include "StatModificationManager.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API UStatModificationManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UStatModificationManager();
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParameterModifiedEvent, const FGameplayTag &, ParameterTag, float, Value);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAssetModifiedEvent, const FGameplayTag &, AssetParameterTag, UObject *, Value);

private:
    UPROPERTY()
    TMap<FGameplayTag, float> _parametersCache;
    UPROPERTY()
    TMap<FGameplayTag, UObject *> _assetsCache;

    UPROPERTY()
    TMap<FName, FModifier> _activeModifiers;

    UPROPERTY()
    TMap<FGameplayTag, float> _finalParameters;

private:
    virtual void EvaluateParameters();
    virtual void OverrideAssets();
    virtual void RecalculateModifications();

    virtual void MarkAsDirty(const FModifier &modifier);
    TSet<FGameplayTag> _dirtyParameters;
    TSet<FGameplayTag> _dirtyAssets;

public:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    /// Applies provided modificator
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void ApplyModificator(const FName &ModificatorID, const FModifier &inModifier);

    /// Remove target modificator
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void RemoveModificator(const FName &ModificatorID);

    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void RemoveAllModificators();

    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    float GetModifiedParamByTag(const FGameplayTag &Tag);

    /// Calls whenewer cached parameter was modified
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnParameterModifiedEvent OnParameterModified;

    // Calls whenewer asset was modified
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnAssetModifiedEvent OnAssetModified;
};