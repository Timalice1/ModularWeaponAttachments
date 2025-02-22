#pragma once

#include "CoreMinimal.h"
#include "AttachmentModuleTypes.generated.h"

UENUM()
enum class EAttachmentModuleTypes : uint8
{
    Scope,
    Mount,
    Optics,
    Muzzle,
    Magazine,
    Grip
};
