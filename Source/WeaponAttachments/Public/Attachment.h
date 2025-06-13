#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "PerksSystem/StatModifier.h"
#include "Attachment.generated.h"

/// @brief Attachment module configuration struct, edited in DataTable
USTRUCT()
struct FAttachmentModuleData : public FTableRowBase
{
    GENERATED_BODY()

    /// @brief Display name of module, using for dispaying and accesing to this module
    UPROPERTY(EditDefaultsOnly, Category = ModuleConfig)
    FName DisplayName;

    /// @brief Detect if this only visual module, without any own logic
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig)
    bool bVisualOnly = true;

    /// @brief Mesh for a visual module only
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig,
              meta = (EditConditionHides, EditCondition = "bVisualOnly"))
    TSoftObjectPtr<UStaticMesh> Mesh;

    /// @brief Attachment module class reference
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModuleConfig,
              meta = (EditConditionHides, EditCondition = "!bVisualOnly"))
    TSubclassOf<class AAttachmentModule> attachmentModuleActorClass;

    /**
     * @brief Attachment module type
     *        Works in pair with a slot type (see: FAttachmentSlot::slotType)
     */
    UPROPERTY(EditDefaultsOnly, Category = ModuleConfig)
    uint8 ModuleType;

    UPROPERTY(EditDefaultsOnly, Category = ModuleConfig)
    FModifier StatModifiers;

    /** @brief Child attachment slots
     *          Leave it empty if module didnt have any childs
     */
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

/*
 * Base class for a attachment modules
 * Minimum logic, leave this up to the end user
 */
UCLASS(Abstract)
class WEAPONATTACHMENTS_API AAttachmentModule : public AActor
{
    GENERATED_BODY()

public:
    AAttachmentModule() {};

    /// @brief Attachment module data property
    FAttachmentModuleData moduleData;

    /// @return Module mesh component reference
    UFUNCTION(BlueprintNativeEvent, Category = AttachmentModule)
    class UMeshComponent *GetModuleMesh() const;

    UFUNCTION(BlueprintCallable, Category = AttachmentModule)
    virtual FModifier GetModificators() const { return moduleData.StatModifiers; }

    /**
     * @brief
     *      Activate/Deactivate current module
     *      can be overrided both in c++ and Blueprints
     *      In c++ override SetModuleActive_Implementation function
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = AttachmentModule)
    void SetModuleActive(bool IsActive);
    void SetModuleActive_Implementation(bool IsActive) {};
};

/**
 * Internal attachment module component class
 * for visual representation only, internal usage
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
    virtual class UMeshComponent *GetModuleMesh_Implementation() const override;
};