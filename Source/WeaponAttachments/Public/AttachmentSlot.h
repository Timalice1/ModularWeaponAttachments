#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.generated.h"

enum class EAttachmentModuleTypes : uint8;

USTRUCT(BlueprintType)
struct FAttachmentSlot
{
    GENERATED_BODY()

    /* Use for display name and accessing to slot*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentSlot)
    FName SlotName = FName("AttachmentSlot");

    /* Named socket on the parent mesh, where module needs to be attached*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AttachmentSlot)
    FName SocketName;

    UPROPERTY(EditDefaultsOnly, Category = AttachmentSlot)
    EAttachmentModuleTypes slotType;

    UPROPERTY()
    class UMeshComponent *CurrentModule;
    UPROPERTY()
    class UMeshComponent *parent;

    friend uint32 GetTypeHash(const FAttachmentSlot &Other)
    {
        return FCrc::MemCrc32(&Other, sizeof(FAttachmentSlot));
    }

    bool operator==(const FAttachmentSlot &Other) const
    {
        return SlotName == Other.SlotName;
    }
};