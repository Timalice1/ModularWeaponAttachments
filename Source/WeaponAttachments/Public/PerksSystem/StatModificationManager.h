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
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnParameterModifiedNotify);
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
    UPROPERTY()
    TMap<FGameplayTag, UObject *> _finalAssets;

    virtual void MarkAsDirty(const FModifier &modifier);
    TSet<FGameplayTag> _dirtyParameters;
    TSet<FGameplayTag> _dirtyAssets;

private:
    virtual void RecalculateModifications();
    virtual void EvaluateParameters();
    virtual void OverrideAssets();

public:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    /// Applies provided modificator
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void ApplyModificator(const FName &ModificatorID, const FModifier &inModifier);

    /// Remove target modificator
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void RemoveModificator(const FName &ModificatorID);

    /// Removes all modificator from owner
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    void RemoveAllModificators();

    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    TMap<FGameplayTag, FParamModifier> GetModificatorByID(const FName &ModificatorID) const;

    /// Returns all modified parameters
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    TMap<FGameplayTag, float> GetModifiedParameters() const { return _finalParameters; }

    /// Find final modified parameter by their tag
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    float GetModifiedParamByTag(const FGameplayTag &Tag) const;

    /// Returns normalized value of required parameter [0, 1]
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    float GetModifiedParamByTagNormalized(const FGameplayTag &InTag, const float ValueMin = 0.f, const float ValueMax = 1.f) const;

    /// Returns final overrided asset value
    UFUNCTION(BlueprintCallable, Category = ModificationsManager)
    UObject *GetModifiedAssetByTag(const FGameplayTag &Tag);

    /// Templated version of GetModifiedParamByTag() function
    template <typename T>
    T GetModifiedParamByTag(const FGameplayTag &Tag)
    {
        static_assert(std::is_arithmetic<T>::value, "Template must be a numeric type");
        return static_cast<T>(this->GetModifiedParamByTag(Tag));
    }

    /// Templated version of GetModifiedAssetByTag() function
    template <class T>
    T *GetModifiedAssetByTag(const FGameplayTag &Tag)
    {
        return Cast<T>(this->GetModifiedAssetByTag(Tag));
    }

    /// Calls whenewer cached parameter was modified
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnParameterModifiedNotify OnParamModifiedNotify;

    /// Calls whenewer cached parameter was modified
    /// Provide modified parameter data
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnParameterModifiedEvent OnParameterModified;

    // Calls whenewer asset was modified
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnAssetModifiedEvent OnAssetModified;
};