#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttachmentSlot.h"
#include "Attachment.h"
#include "GameFramework/Actor.h"
#include "WeaponAttachmentsManager.generated.h"

enum class EAttachmentModuleTypes : uint8;

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class WEAPONATTACHMENTS_API UWeaponAttachmentsManager : public UActorComponent
{
    GENERATED_BODY()

    TObjectPtr<class UMeshComponent> ownerMeshComponent;
    /* Add a new slot*/
    virtual void AddSlot(FAttachmentSlot &slot, class UMeshComponent *parent);

public:
    virtual FAttachmentSlot *FindSlotByName(const FName &SlotName);
    virtual FAttachmentSlot *FindSlotByType(const EAttachmentModuleTypes type);

public:
    UWeaponAttachmentsManager();
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    virtual void SetBaseWeaponMeshComponent(class UMeshComponent *baseWeaponMesh) { ownerMeshComponent = baseWeaponMesh; };

    UFUNCTION(BlueprintCallable)
    TArray<FAttachmentSlot> GetActiveSlots() { return _activeSlots; };

    UFUNCTION(BlueprintCallable)
    TArray<FAttachmentModuleData> GetCompatibleAttachments();

    UFUNCTION(BlueprintCallable)
    TArray<FAttachmentModuleData> GetCompatibleAttachmentsByType(EAttachmentModuleTypes moduleType);

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
    /* Default weapon attachment slots (persistant)*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentsManager)
    TSet<FAttachmentSlot> attachmentSlots;

    UPROPERTY(EditDefaultsOnly, Category = AttachmentsManager)
    TSet<FAttachmentModuleData> compatibleAttachments;

    /* Active attachment slots, includes child slots from attachments*/
    TArray<FAttachmentSlot> _activeSlots;
};