#include "UI/SlotWidget.h"
#include "UI/DropDown.h"
#include "Components/TextBlock.h"
#include "WeaponAttachmentsManager.h"

void USlotWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
}

void USlotWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!attachmentsManager)
        return;
    UComboBoxKey *comboBox = modulesList->GetComboBox();
    if (!comboBox)
        return;

    compatibleAttachments = attachmentsManager->GetCompatibleAttachmentsForSlot(slotData.SlotName);

    /* Filter compatible attachments by already installed*/
    const auto activeAttachments = attachmentsManager->GetActiveAttachmentsByType(slotData.slotType);
    compatibleAttachments = compatibleAttachments.FilterByPredicate(
        [&](const FAttachmentModuleData &compatibleItem)
        {
            return !activeAttachments.ContainsByPredicate(
                [&](const AAttachmentModule *activeItem)
                {
                    return activeItem->moduleData == compatibleItem &&
                           activeItem != slotData.CurrentModule;
                });
        });

    comboBox->ClearOptions();
    comboBox->AddOption(FName("Empty"));
    comboBox->SetSelectedOption(FName("Empty"));

    FAttachmentModuleData defaultModule = attachmentsManager->GetDefaultAttahcment(slotData.SlotName);
    for (FAttachmentModuleData &moduleData : compatibleAttachments)
    {
        if (moduleData != defaultModule)
            comboBox->AddOption(moduleData.DisplayName);
    }

    if (AAttachmentModule *currentModule = slotData.CurrentModule)
    {
        if (currentModule->moduleData != defaultModule)
            comboBox->SetSelectedOption(currentModule->moduleData.DisplayName);
    }

    modulesList->OnOpening.AddDynamic(this, &ThisClass::HandleOpening);
    modulesList->OnClosing.AddDynamic(this, &ThisClass::HandleClosing);
    modulesList->OnSelectionChanged.AddDynamic(this, &ThisClass::HandleSelectionChanged);
}

void USlotWidget::SetVisible(bool bVisible)
{
    ESlateVisibility newVis = bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed;
    modulesList->SetVisibility(newVis);
}

void USlotWidget::SetAttachmentsManager(UWeaponAttachmentsManager *inManager)
{
    attachmentsManager = inManager;
}

void USlotWidget::SetSlotData(FAttachmentSlot inSlotData)
{
    slotData = inSlotData;
}

void USlotWidget::HandleSelectionChanged(FName SelectedItem, ESelectInfo::Type SelectionType)
{
    if (SelectedItem == FName("Empty"))
    {
        attachmentsManager->InstallDefault(slotData.SlotName);
        OnSelectionChanged.Broadcast(SelectedItem);
        return;
    }

    FAttachmentModuleData *targetModule =
        compatibleAttachments.FindByPredicate([SelectedItem](const FAttachmentModuleData &item)
                                              { return item.DisplayName == SelectedItem; });
    if (!targetModule)
        return;

    attachmentsManager->InstallModule(slotData.SlotName, *targetModule);
    OnSelectionChanged.Broadcast(SelectedItem);
}

void USlotWidget::HandleOpening()
{
    OnOpened.Broadcast(this);
}

void USlotWidget::HandleClosing()
{
    OnClosed.Broadcast();
}