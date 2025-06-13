#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "ModifiableInterface.generated.h"

/// Pass target map, property name, and any numeric parameter, that would be converted into float
#define MAP_PARAM_PROPERTY(Map, Key, Value) Map.Add(FGameplayTag(Key), static_cast<float>(Value))
#define MAP_ASSET_PROPERTY(Map, Key, Value) Map.Add(FGameplayTag(Key), Value)

UINTERFACE(MinimalAPI)
class UModifiableInterface : public UInterface
{
    GENERATED_BODY()
};

class WEAPONATTACHMENTS_API IModifiableInterface
{
    GENERATED_BODY()

public:
    /**
     * @param parametersCache default owner parameters, that can be modified
     * @param assetsCache Caching default owner assets, that can be modified
     * Ensure cached parameters key tags are exact match with a keys in paramModifiers
     * (see. FModifier.ParametersModificators, FModifier.AssetsOverrides)
     */
    UFUNCTION(BlueprintNativeEvent, Category = ModifiableInterface)
    void MapDefaultProperties(TMap<FGameplayTag, float> &parametersCache, TMap<FGameplayTag, UObject *> &assetsCache);
};