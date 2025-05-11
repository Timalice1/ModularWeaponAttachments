#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.h"
#include "Attachment.generated.h"

/**
 * Struct data for weapon stats modifying
 */
USTRUCT(BlueprintType)
struct FModifier
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    TMap<FName, float> paramOverride;
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, TSoftObjectPtr<UObject>> assetOverride;
};

/**
 * Generic attachment properties, edited in DataTable
 */
USTRUCT()
struct FAttachmentModuleData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, Category = ModuleConfig)
    FName DisplayName;

    /* Detect if this only visual module, without any own logic*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig)
    bool bVisualOnly = true;

    /* @todo Remove and replace with AAttachmnentModule subclass*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig,
              meta = (EditConditionHides, EditCondition = "bVisualOnly"))
    class UStaticMesh *Mesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig,
              meta = (EditConditionHides, EditCondition = "!bVisualOnly"))
    TSubclassOf<class AAttachmentModule> attachmentModuleActorClass;

    UPROPERTY(EditDefaultsOnly, Category = ModuleConfig)
    uint8 ModuleType;

    /*Child attachment slots*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig)
    TSet<FAttachmentSlot> childSlots;

    friend uint32 GetTypeHash(const FAttachmentModuleData &Other)
    {
        return GetTypeHash(Other.DisplayName);
    }
    
    inline bool operator==(const FAttachmentModuleData &Other) const
    {
        return DisplayName == Other.DisplayName;
    }
};

/**
 * Base class for a attachment modules
 * Minimum logic, leave this up to the end user
 */
UCLASS(Abstract)
class WEAPONATTACHMENTS_API AAttachmentModule : public AActor
{
    GENERATED_BODY()

public:
    AAttachmentModule() {};
    FAttachmentModuleData moduleData;

    UFUNCTION(BlueprintNativeEvent, Category = AttachmentModule)
    class UMeshComponent *GetAttachmentModuleParent() const;
};

/**
 * Internal attachment module component class
 * for visual representation only
 */
UCLASS(NotBlueprintable, NotBlueprintType)
class WEAPONATTACHMENTS_API AAttachmentModule_VisualOnly : public AAttachmentModule
{
    GENERATED_BODY()
protected:
    UPROPERTY()
    TObjectPtr<class UStaticMeshComponent> staticMeshComponent = nullptr;

public:
    AAttachmentModule_VisualOnly();
    void SetMesh(class UStaticMesh *mesh);

private:
    virtual class UMeshComponent *GetAttachmentModuleParent_Implementation() const override;
};
