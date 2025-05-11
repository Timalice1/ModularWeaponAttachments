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
    InstallDefault(slot.SlotName);
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
    if (_activeModules.ContainsByPredicate([moduleData](const AAttachmentModule *activeModule)
                                           { return activeModule->moduleData == moduleData; }))
    { // Remove and install default if truing to install same module on slot
        InstallDefault(SlotName);
        return;
    }
    RemoveModule(SlotName);

    TSubclassOf<AAttachmentModule> moduleClass =
        moduleData.bVisualOnly
            ? TSubclassOf<AAttachmentModule>(AAttachmentModule_VisualOnly::StaticClass())
            : moduleData.attachmentModuleActorClass;

    TObjectPtr<AAttachmentModule> moduleInstance = GetWorld()->SpawnActor<AAttachmentModule>(moduleClass);
    if (!moduleInstance)
        return;

    if (moduleData.bVisualOnly)
    {
        if (AAttachmentModule_VisualOnly *visualModule = Cast<AAttachmentModule_VisualOnly>(moduleInstance))
            visualModule->SetMesh(moduleData.Mesh);
    }
    if (_targetSlot->parent)
        moduleInstance->AttachToComponent(_targetSlot->parent, FAttachmentTransformRules::SnapToTargetIncludingScale, _targetSlot->SocketName);
    moduleInstance->moduleData = moduleData;
    _targetSlot->CurrentModule = moduleInstance;
    _activeModules.Add(moduleInstance);

    // Add child slots to global active slots list
    if (!moduleData.childSlots.IsEmpty())
    {
        for (FAttachmentSlot &slot : moduleData.childSlots.Array())
            AddSlot(slot, moduleInstance->GetAttachmentModuleParent());
    }

    OnModuleInstalled.Broadcast(moduleInstance);
}

void UWeaponAttachmentsManager::RemoveModule(const FName &SlotName)
{
    // Find the target slot
    FAttachmentSlot *TargetSlot = FindSlotByName(SlotName);
    if (!TargetSlot || !TargetSlot->CurrentModule)
    {
        UE_LOG(LogTemp, Warning, TEXT("Slot [%s] not found or already empty"), *SlotName.ToString());
        return;
    }

    TArray<FAttachmentSlot> childSlots =
        _activeSlots.FilterByPredicate([TargetSlot](const FAttachmentSlot &slot)
                                       { return slot.parent == TargetSlot->CurrentModule->GetAttachmentModuleParent(); });

    // Recursively remove child modules
    for (FAttachmentSlot &ChildSlot : childSlots)
    {
        RemoveModule(ChildSlot.SlotName);
        _activeSlots.Remove(ChildSlot);
    }

    // Remove the target module
    _activeModules.Remove(TargetSlot->CurrentModule);
    OnModuleRemoved.Broadcast(TargetSlot->CurrentModule);

    // Clean up the module and slotF
    TargetSlot->CurrentModule->Destroy();
    TargetSlot->CurrentModule = nullptr;
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

void UWeaponAttachmentsManager::InstallDefault(const FName &slotName)
{
    /*Remove existing module first*/
    RemoveModule(slotName);

    /* Find target slot*/
    FAttachmentSlot *targetSlot = FindSlotByName(slotName);
    if (!targetSlot || !AttachmentsTable || targetSlot->DefaultAttachment == NAME_None)
        return;

    if (FAttachmentModuleData *defaultModule = AttachmentsTable->FindRow<FAttachmentModuleData>(targetSlot->DefaultAttachment, FString(TEXT("InstallDefault: Looking up default module"))))
    {
        InstallModule(slotName, *defaultModule);
        return;
    }
    UE_LOG(LogTemp, Error, TEXT("%s: Requested module not found"), *targetSlot->DefaultAttachment.ToString());
}

FAttachmentModuleData UWeaponAttachmentsManager::GetDefaultAttahcment(FName slot)
{
    FAttachmentSlot *_targetSlot = FindSlotByName(slot);
    if (!_targetSlot)
        return FAttachmentModuleData();
    FAttachmentModuleData *defaultModule = AttachmentsTable->FindRow<FAttachmentModuleData>(_targetSlot->DefaultAttachment, FString());
    if (defaultModule)
        return *defaultModule;
    return FAttachmentModuleData();
}