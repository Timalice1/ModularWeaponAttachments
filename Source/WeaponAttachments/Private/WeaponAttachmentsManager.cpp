#include "WeaponAttachmentsManager.h"

UWeaponAttachmentsManager::UWeaponAttachmentsManager()
{
    PrimaryComponentTick.bCanEverTick = false;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UWeaponAttachmentsManager::BeginPlay()
{
    Super::BeginPlay();

    if (!ownerMeshComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("WeaponAttachmetnsManager - missing reference to owner mesh component\n"
                                      "\tUse SetBaseWeaponMeshComponent() to do that"));
        return;
    }

    for (FAttachmentSlot &slot : attachmentSlots)
        AddSlot(slot, ownerMeshComponent);
}

void UWeaponAttachmentsManager::AddSlot(FAttachmentSlot &slot, UMeshComponent *parent)
{
    slot.parent = parent;
    _activeSlots.Add(slot);
    InstallDefault(slot);
}

FAttachmentSlot *UWeaponAttachmentsManager::FindSlotByName(const FName &SlotName)
{
    FAttachmentSlot *_targetSlot =
        _activeSlots.FindByPredicate([SlotName](const FAttachmentSlot &slot)
                                     { return slot.SlotName == SlotName; });
    return _targetSlot;
}

FAttachmentSlot *UWeaponAttachmentsManager::FindSlotByType(const uint8 type)
{
    FAttachmentSlot *_targetSlot =
        _activeSlots.FindByPredicate([type](const FAttachmentSlot &slot)
                                     { return slot.slotType == type; });
    return _targetSlot;
}

void UWeaponAttachmentsManager::InstallModule(const FName &SlotName, const FAttachmentModuleData &moduleData)
{
    // Get the required slot where attachment need to be installed
    FAttachmentSlot *_targetSlot = FindSlotByName(SlotName);
    if (!_targetSlot)
    {
        UE_LOG(LogTemp, Warning, TEXT("Requested slot [%s] does not exist"), *SlotName.ToString());
        return;
    }

    // Remove existing module and child slots before adding new one
    if (_activeAttachments.FindByPredicate([moduleData](const UAttachmentModuleComponent *activeModule)
                                           { return activeModule->moduleData == moduleData; }))
    { // Remove and install default if truing to install same module on slot
        // RemoveModule(SlotName);
        InstallDefault(*_targetSlot);
        return;
    }
    RemoveModule(SlotName);

    UAttachmentModuleComponent *newComp = NewObject<UAttachmentModuleComponent>(GetOwner(), UAttachmentModuleComponent::StaticClass(), SlotName);
    if (!newComp)
        return;

    newComp->AttachToComponent(_targetSlot->parent, FAttachmentTransformRules::SnapToTargetIncludingScale, _targetSlot->SocketName);
    newComp->SetStaticMesh(moduleData.Mesh);
    newComp->SetCollisionProfileName("NoCollision");
    newComp->moduleData = moduleData;
    newComp->RegisterComponent();
    _targetSlot->CurrentModule = newComp;
    _activeAttachments.Add(newComp);

    // Add child slots to global active slots list
    if (!moduleData.childSlots.IsEmpty())
    {
        for (FAttachmentSlot &slot : moduleData.childSlots.Array())
            AddSlot(slot, newComp);
    }

    OnModuleInstalled.Broadcast(newComp, moduleData.ModuleType);
}

void UWeaponAttachmentsManager::RemoveModule(const FName &SlotName)
{
    // Find requested slot
    FAttachmentSlot *_targetSlot = FindSlotByName(SlotName);
    if (!_targetSlot || !_targetSlot->CurrentModule)
    {
        UE_LOG(LogTemp, Warning, TEXT("Requested slot [%s] does not exist, or already empty"), *SlotName.ToString());
        return;
    }

    TArray<FAttachmentSlot> childSlots =
        _activeSlots.FilterByPredicate([_targetSlot](const FAttachmentSlot &slot)
                                       { return slot.parent == _targetSlot->CurrentModule; });

    // Recursively remove child modules and slots
    for (FAttachmentSlot &childSlot : childSlots)
    {
        RemoveModule(childSlot.SlotName);
        const int32 index = _activeSlots.IndexOfByKey(childSlot);
        _activeSlots.RemoveAtSwap(index, 1, EAllowShrinking::No);
    }
    _activeSlots.Shrink();

    _activeAttachments.Remove(_targetSlot->CurrentModule);
    OnModuleRemoved.Broadcast(_targetSlot->CurrentModule, _targetSlot->CurrentModule->moduleData.ModuleType);

    _targetSlot->CurrentModule->DestroyComponent(true);
    _targetSlot->CurrentModule = nullptr;
}

TArray<FAttachmentModuleData> UWeaponAttachmentsManager::GetCompatibleAttachments()
{
    if (!IsValid(AttachmentsTable))
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s-%s]: missing attachments data table property reference"), *GetOwner()->GetName(), *GetName());
        return TArray<FAttachmentModuleData>();
    }

    if (compatibleAttachments.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s - %s]: compatible attachments list are empty"), *GetOwner()->GetName(), *GetName());
        return TArray<FAttachmentModuleData>();
    }

    TArray<FAttachmentModuleData> outRows;
    for (const FName &rowName : compatibleAttachments)
    {
        FAttachmentModuleData *rowFound = AttachmentsTable->FindRow<FAttachmentModuleData>(rowName, FString());
        if (rowFound)
            outRows.Add(*rowFound);
    }
    return outRows;
}

TArray<FAttachmentModuleData> UWeaponAttachmentsManager::GetCompatibleAttachmentsByType(uint8 moduleType)
{
    return GetCompatibleAttachments().FilterByPredicate([moduleType](const FAttachmentModuleData &attachmentModule)
                                                        { return attachmentModule.ModuleType == moduleType; });
}

void UWeaponAttachmentsManager::InstallDefault(FAttachmentSlot &slot)
{
    /*Remove existing module first*/
    RemoveModule(slot.SlotName);

    if (!AttachmentsTable || slot.DefaultAttachment == NAME_None)
        return;

    FAttachmentModuleData *defaultModule = AttachmentsTable->FindRow<FAttachmentModuleData>(slot.DefaultAttachment, FString());
    if (!defaultModule)
    {
        UE_LOG(LogTemp, Error, TEXT("%s: Requested module not found"), *slot.DefaultAttachment.ToString());
        return;
    }
    InstallModule(slot.SlotName, *defaultModule);
}