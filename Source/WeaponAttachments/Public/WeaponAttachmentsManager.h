#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttachmentSlot.h"
#include "Attachment.h"
#include "GameFramework/Actor.h"
#include "WeaponAttachmentsManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModuleInstalledEvent, class AAttachmentModule *, module);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModuleRemovedEvent, class AAttachmentModule *, module);

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class WEAPONATTACHMENTS_API UWeaponAttachmentsManager : public UActorComponent
{
    GENERATED_BODY()

    TObjectPtr<class UMeshComponent> ownerMeshComponent;

    /* Add a new slot*/
    virtual void AddSlot(FAttachmentSlot &slot, class UMeshComponent *parent);

    UPROPERTY() /* Active attachment slots, includes child slots from attachments*/
    TArray<FAttachmentSlot> _activeSlots;

    UPROPERTY() /* Currently used attachment modules on the weapon*/
    TArray<TObjectPtr<class AAttachmentModule>> _activeModules;

protected: // Properties
    /// Attachment modules configuration data table
    UPROPERTY(EditDefaultsOnly, Category = AttachmentsManager, meta = (RequiredAssetDataType = "FAttachmentModuleData"))
    TObjectPtr<class UDataTable> AttachmentsTable;

    /// Default weapon attachment slots (persistant)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentsManager)
    TSet<FAttachmentSlot> attachmentSlots;

    UFUNCTION()
    TArray<FName> GetAttachmentsTableRows() const
    {
        if (AttachmentsTable)
            return AttachmentsTable->GetRowNames();
        return TArray<FName>();
    };

    /// Per-weapon compatible modules row names
    UPROPERTY(EditDefaultsOnly, Category = AttachmentsManager, meta = (GetOptions = "GetAttachmentsTableRows"))
    TSet<FName> compatibleAttachments;

public:
    UWeaponAttachmentsManager();

    UFUNCTION()
    virtual void BeginPlay() override;

    /// Set parent actor item mesh (where the slots and modules should be Attached)
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual void SetBaseWeaponMeshComponent(class UMeshComponent *baseWeaponMesh) { ownerMeshComponent = baseWeaponMesh; };

    /// Install required module in specific module slot
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual bool InstallModule(const FName &SlotName, const struct FAttachmentModuleData &moduleData);

    /// Install default attachment for specific slot
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual void InstallDefault(const FName &slotName);

    /// Remove current module crom specific slot
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual bool RemoveModule(const FName &SlotName = FName("ModuleSlot"));

    /// @return array of all active slots on the owner
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<FAttachmentSlot> GetActiveSlots() { return _activeSlots; };

    /// @return all active attachment modules
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<class AAttachmentModule *> GetActiveAttachments() { return _activeModules; };

    /// @param type module type value to filter by
    /// @return all active attachment modules, filtered by required type
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<class AAttachmentModule *> GetActiveAttachmentsByType(uint8 type)
    {
        return _activeModules.FilterByPredicate([type](const AAttachmentModule *attachment)
                                                { return attachment->moduleData.ModuleType == type; });
    };

    /// @return all compatible attachments for this weapon
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<FAttachmentModuleData> GetCompatibleAttachments();

    /// @param moduleType module type value to filter by
    /// @return all compatible attachments for this weapon, filtered by provided type
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<FAttachmentModuleData> GetCompatibleAttachmentsByType(uint8 moduleType);

    /// @return all compatible attachments for specific weapon
    /// per-slot compatible attachments must be provided inside attachment slot struct config
    /// if pre-slot compatible attachments is not provided, returns compatible attachments filtered by slot type
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<FAttachmentModuleData> GetCompatibleAttachmentsForSlot(const FName &slotName);

    /// @return all compatible and available attachments to install for specific slot
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    TArray<FAttachmentModuleData> GetAvailableAttachmentsForSlot(const FName &slotName);

    /// @return Default attachment module property for specific slot
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    FAttachmentModuleData GetDefaultAttahcment(FName slot);

    /// Helper function, looks for a attachment slot by their name
    virtual FAttachmentSlot *FindSlotByName(const FName &SlotName);

    /// Helper function, looks for a attachment slot by their type
    virtual FAttachmentSlot *FindSlotByType(const uint8 type);

public: // Events
    /// Called whenever new module was succesfully installed
    UPROPERTY(BlueprintAssignable, Category = "AttachmentsManager|Events")
    FOnModuleInstalledEvent OnModuleInstalled;

    /// Called whenever module succesfully removed
    UPROPERTY(BlueprintAssignable, Category = "AttachmentsManager|Events")
    FOnModuleRemovedEvent OnModuleRemoved;
};