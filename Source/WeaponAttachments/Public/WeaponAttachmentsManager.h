#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttachmentSlot.h"
#include "Attachment.h"
#include "GameFramework/Actor.h"
#include "WeaponAttachmentsManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttachmentInstalledSignature, class UAttachmentModuleComponent*, ModuleComponent);

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class WEAPONATTACHMENTS_API UWeaponAttachmentsManager : public UActorComponent
{
    GENERATED_BODY()

    TObjectPtr<class UMeshComponent> ownerMeshComponent;
    /* Add a new slot*/
    virtual void AddSlot(FAttachmentSlot &slot, class UMeshComponent *parent);

public:
    virtual FAttachmentSlot *FindSlotByName(const FName &SlotName);
    virtual FAttachmentSlot *FindSlotByType(const uint8 type);

public:
    UWeaponAttachmentsManager();
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    virtual void SetBaseWeaponMeshComponent(class UMeshComponent *baseWeaponMesh) { ownerMeshComponent = baseWeaponMesh; };

    UFUNCTION(BlueprintCallable)
    TArray<FAttachmentSlot> GetActiveSlots() { return _activeSlots; };
    UFUNCTION(BlueprintCallable)
    TArray<class UAttachmentModuleComponent *> GetActiveAttachments() { return _activeAttachments; };
    TArray<class UAttachmentModuleComponent *> GetActiveAttachmentsByType(uint8 type)
    {
        return _activeAttachments.FilterByPredicate([type](const UAttachmentModuleComponent *attachment)
                                                    { return attachment->moduleData.ModuleType == type; });
    };

    TArray<FAttachmentModuleData> GetCompatibleAttachments();
    TArray<FAttachmentModuleData> GetCompatibleAttachmentsByType(uint8 moduleType);

    UPROPERTY(BlueprintAssignable)
    FOnAttachmentInstalledSignature OnModuleInstalled;

public:
    /**
     * @brief Install new module to required slot
     * @param SlotName required slot name
     * @param moduleData new module data to install
     */
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual void InstallModule(const FName &SlotName, const struct FAttachmentModuleData &moduleData);

    /**
     * @brief Remove current active module from required slot
     * @param SlotName Required slot name
     */
    UFUNCTION(BlueprintCallable, Category = AttachmentsManager)
    virtual void RemoveModule(const FName &SlotName = FName("ModuleSlot"));

protected:
    UPROPERTY(EditDefaultsOnly, Category = AttachmentsManager)
    TObjectPtr<class UDataTable> AttachmentsTable;

    /* Default weapon attachment slots (persistant)*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentsManager)
    TSet<FAttachmentSlot> attachmentSlots;

    UFUNCTION()
    TArray<FName> GetAttachmentsTableRows() const
    {
        if (AttachmentsTable)
            return AttachmentsTable->GetRowNames();
        return TArray<FName>();
    };

    UPROPERTY(EditDefaultsOnly, Category = AttachmentsManager, meta = (GetOptions = "GetAttachmentsTableRows"))
    TSet<FName> compatibleAttachments;

private:
    /* Active attachment slots, includes child slots from attachments*/
    TArray<FAttachmentSlot> _activeSlots;
    /* Currently used attachment modules on the weapon*/
    UPROPERTY()
    TArray<TObjectPtr<class UAttachmentModuleComponent>> _activeAttachments;
};