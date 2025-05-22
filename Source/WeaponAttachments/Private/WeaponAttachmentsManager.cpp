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
    return _activeSlots.FindByPredicate([SlotName](const FAttachmentSlot &slot)
                                        { return slot.SlotName == SlotName; });
}

FAttachmentSlot *UWeaponAttachmentsManager::FindSlotByType(const uint8 type)
{
    return _activeSlots.FindByPredicate([type](const FAttachmentSlot &slot)
                                        { return slot.slotType == type; });
}

bool UWeaponAttachmentsManager::InstallModule(const FName &SlotName, const FAttachmentModuleData &moduleData)
{
    // Get the required slot where attachment need to be installed
    FAttachmentSlot *_targetSlot = FindSlotByName(SlotName);
    if (!_targetSlot)
    {
        UE_LOG(LogTemp, Warning, TEXT("Requested slot [%s] does not exist"), *SlotName.ToString());
        return false;
    }

    // Remove existing module and child slots before adding new one
    if (_activeModules.ContainsByPredicate([moduleData](const AAttachmentModule *activeModule)
                                           { return activeModule->moduleData == moduleData; }))
    { // Remove and install default if truing to install same module on slot
        InstallDefault(SlotName);
        return false;
    }
    RemoveModule(SlotName);

    /*If its a visual only module, spawn internal visual-only subclass of AttachmentModule*/
    TSubclassOf<AAttachmentModule> moduleClass =
        moduleData.bVisualOnly
            ? TSubclassOf<AAttachmentModule>(AAttachmentModule_VisualOnly::StaticClass())
            : moduleData.attachmentModuleActorClass;

    /*Spawn new module actor*/
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    TObjectPtr<AAttachmentModule> moduleInstance = GetWorld()->SpawnActor<AAttachmentModule>(moduleClass, SpawnParams);
    if (!moduleInstance)
        return false;

    /*if that is visual-only module, setup their mesh*/
    if (moduleData.bVisualOnly)
    {
        if (TObjectPtr<AAttachmentModule_VisualOnly> visualModule = Cast<AAttachmentModule_VisualOnly>(moduleInstance))
            visualModule->SetMesh(moduleData.Mesh);
    }

    /* attach new module actor to a target slot*/
    if (_targetSlot->parent)
        moduleInstance->AttachToComponent(_targetSlot->parent, FAttachmentTransformRules::SnapToTargetIncludingScale, _targetSlot->SocketName);
    moduleInstance->moduleData = moduleData;
    _targetSlot->CurrentModule = moduleInstance;
    _activeModules.Add(moduleInstance);

    // Add child slots to global active slots list
    if (!moduleData.childSlots.IsEmpty())
    {
        for (FAttachmentSlot &slot : moduleData.childSlots.Array())
            AddSlot(slot, moduleInstance->GetModuleMesh());
    }

    /*Callback (assigns on weapon class)*/
    OnModuleInstalled.Broadcast(moduleInstance);
    return true;
}

bool UWeaponAttachmentsManager::RemoveModule(const FName &SlotName)
{
    // Find the target slot
    FAttachmentSlot *TargetSlot = FindSlotByName(SlotName);
    if (!TargetSlot || !TargetSlot->CurrentModule)
    {
        UE_LOG(LogTemp, Warning, TEXT("Slot [%s] not found or already empty"), *SlotName.ToString());
        return false;
    }

    TArray<FAttachmentSlot> childSlots =
        _activeSlots.FilterByPredicate([TargetSlot](const FAttachmentSlot &slot)
                                       { return slot.parent == TargetSlot->CurrentModule->GetModuleMesh(); });

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
    return true;
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

TArray<FAttachmentModuleData> UWeaponAttachmentsManager::GetCompatibleAttachmentsForSlot(const FName &slotName)
{
    FAttachmentSlot *_targetSlot = FindSlotByName(slotName);
    if (!_targetSlot)
    {
        UE_LOG(LogTemp, Warning, TEXT("Slot [%s] not found"), *slotName.ToString());
        return TArray<FAttachmentModuleData>();
    }

    /* Find compatible attachments by slot type, if slot attachment list was empty*/
    if (_targetSlot->compatibleAttachments.IsEmpty())
        return GetCompatibleAttachmentsByType(_targetSlot->slotType);

    TArray<FAttachmentModuleData> outRows;
    for (const FName &rowName : _targetSlot->compatibleAttachments)
    {
        FAttachmentModuleData *rowFound = AttachmentsTable->FindRow<FAttachmentModuleData>(rowName, FString());
        if (rowFound)
            outRows.Add(*rowFound);
    }

    return outRows;
}

TArray<FAttachmentModuleData> UWeaponAttachmentsManager::GetAvailableAttachmentsForSlot(const FName &slotName)
{
    FAttachmentSlot *_targetSlot = FindSlotByName(slotName);
    if (!_targetSlot)
    {
        UE_LOG(LogTemp, Warning, TEXT("Slot [%s] does not exist"), *slotName.ToString());
        return TArray<FAttachmentModuleData>();
    }

    TArray<FAttachmentModuleData> availableAttachments = GetCompatibleAttachmentsForSlot(slotName);
    if (availableAttachments.IsEmpty())
        return TArray<FAttachmentModuleData>();

    availableAttachments = availableAttachments.FilterByPredicate(
        [&](const FAttachmentModuleData &compatibleItem)
        {
            return !_activeModules.ContainsByPredicate(
                [&](const AAttachmentModule *activeItem)
                {
                    return activeItem->moduleData == compatibleItem &&
                           activeItem != _targetSlot->CurrentModule;
                });
        });
    return availableAttachments;
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
    if (!AttachmentsTable)
    {
        UE_LOG(LogTemp, Error, TEXT("[%s]: missing reference to attachments data table"), *GetOwner()->GetName());
        return FAttachmentModuleData();
    }

    FAttachmentSlot *_targetSlot = FindSlotByName(slot);
    if (!_targetSlot)
    {
         return FAttachmentModuleData();
    }

    FAttachmentModuleData *defaultModule = AttachmentsTable->FindRow<FAttachmentModuleData>(_targetSlot->DefaultAttachment, FString());
    if (defaultModule)
        return *defaultModule;
    return FAttachmentModuleData();
}