#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.h"
#include "Attachment.generated.h"

enum class EAttachmentModuleTypes : uint8;

USTRUCT()
struct FAttachmentModuleData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, Category = BaseModule)
    FName DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModule)
    class UStaticMesh *Mesh;

    UPROPERTY(EditDefaultsOnly, Category = BaseModule)
    EAttachmentModuleTypes ModuleType;

    /*Child attachment slots*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModule)
    TSet<FAttachmentSlot> childSlots;

    friend uint32 GetTypeHash(const FAttachmentModuleData &Other)
    {
        return FCrc::MemCrc32(&Other, sizeof(FAttachmentModuleData));
    }

    inline bool operator==(const FAttachmentModuleData &Other)
    {
        return DisplayName == Other.DisplayName;
    }
};