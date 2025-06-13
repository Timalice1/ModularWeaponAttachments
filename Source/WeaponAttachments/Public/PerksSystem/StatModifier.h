#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StatModifier.generated.h"

UENUM()
enum class EModifierOp : uint8
{
    /// Percentage operation on current value
    /// set modificator value to e.g 10 for +10%, or -10 for -10%
    Percent,
    /// Replace current parameter value with modificator's one
    Override
};

USTRUCT(BlueprintType)
struct FParamModifier
{
    GENERATED_BODY()

    /// Modificator value
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ParamModifier)
    float Value;

    /// Modificator operation
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ParamModifier)
    EModifierOp ModificationType = EModifierOp::Percent;
};

USTRUCT(BlueprintType)
struct FModifier
{
    GENERATED_BODY()

    /// Param-based modifiers like damage, fire rate, sword swing speed
    /// FName key must match affected cached parameter name
    UPROPERTY(EditDefaultsOnly, Category = ModifierConfig)
    TMap<FGameplayTag, FParamModifier> ParametersModificators;

    /// Asset-based overrides like sounds, particles, VFX
    /// FName key must match affected cached parameter name
    UPROPERTY(EditDefaultsOnly, Category = ModifierConfig)
    TMap<FGameplayTag, TSoftObjectPtr<UObject>> AssetsOverrides;
};