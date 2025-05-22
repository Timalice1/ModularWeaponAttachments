#pragma once

#include "CoreMinimal.h"
#include "StatModifier.generated.h"

/**
 * @brief Weapon stats modifiers struct
 *        Can be used from multiple sources, such for attachment modules or weapon perks modifications
 *        Simply add a property FModifier to a target class and setup that
 */
USTRUCT(BlueprintType)
struct FModifier
{
    GENERATED_BODY()

    /// @brief Float stats modifiers. e.g. WeaponRecoil, accuracy, damage, etc
    /// FName: weapon stat property name
    /// float: modification value
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, float> paramOverride;

    /// @brief visual modificator
    /// Can be used for overriding materials, particles systems or sounds
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, TSoftObjectPtr<UObject>> assetOverride;
};