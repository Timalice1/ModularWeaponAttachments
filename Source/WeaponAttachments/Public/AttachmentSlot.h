#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.generated.h"

USTRUCT(BlueprintType)
struct FAttachmentSlot
{
    GENERATED_BODY()

    /// Use for display name and accessing to slot
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentSlot)
    FName SlotName = FName("AttachmentSlot");

    /// Named socket on the parent mesh, where module needs to be attached
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentSlot)
    FName SocketName;

    /// Slot type value. Uses for filtering compatible attachments for this slot
    UPROPERTY(EditDefaultsOnly, Category = AttachmentSlot)
    uint8 slotType;

    /// Default attachment module table row name
    UPROPERTY(EditDefaultsOnly, Category = AttachmentSlot)
    FName DefaultAttachment = FName("None");

    /// List of compatible attachments row names for this slot
    /// If this was empty, compatible modules will be sorted by their type
    UPROPERTY(EditDefaultsOnly, Category = AttachmentSlot)
    TSet<FName> compatibleAttachments;

    UPROPERTY()
    TObjectPtr<class AAttachmentModule> CurrentModule;

    UPROPERTY()
    TObjectPtr<class UMeshComponent> parent;

    friend uint32 GetTypeHash(const FAttachmentSlot &Other)
    {
        return FCrc::MemCrc32(&Other, sizeof(FAttachmentSlot));
    }

    bool operator==(const FAttachmentSlot &Other) const
    {
        return SlotName == Other.SlotName;
    }
};