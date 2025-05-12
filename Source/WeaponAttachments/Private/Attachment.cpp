#include "Attachment.h"

UMeshComponent *AAttachmentModule::GetModuleMesh_Implementation() const
{
    return nullptr;
}

AAttachmentModule_VisualOnly::AAttachmentModule_VisualOnly()
{
    staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ModuleMesh");
    staticMeshComponent->SetCollisionProfileName("NoCollision");
}

UMeshComponent *AAttachmentModule_VisualOnly::GetModuleMesh_Implementation() const
{
    return staticMeshComponent;
}

void AAttachmentModule_VisualOnly::SetMesh(UStaticMesh *mesh)
{
    staticMeshComponent->SetStaticMesh(mesh);
}
