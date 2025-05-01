#include "UI/SlotWidget.h"
#include "Components/TextBlock.h"
#include "Components/ComboBoxKey.h"
#include "WeaponAttachmentsManager.h"

void USlotWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
    _optionFontColor = FLinearColor::White;
    _contentFontColor = FLinearColor::White;
}

void USlotWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!attachmentsManager)
        return;
    compatibleAttachments = attachmentsManager->GetCompatibleAttachmentsByType(slotData.slotType);

    modulesList->ClearOptions();
    modulesList->AddOption(FName("Empty"));
    modulesList->SetSelectedOption(FName("Empty"));

    FAttachmentModuleData defaultModule = attachmentsManager->GetDefaultAttahcment(slotData.SlotName);
    for (FAttachmentModuleData &moduleData : compatibleAttachments)
    {
        if (moduleData != defaultModule)
            modulesList->AddOption(moduleData.DisplayName);
    }

    if (UAttachmentModuleComponent *currentModule = slotData.CurrentModule)
    {
        if (currentModule->moduleData != defaultModule)
            modulesList->SetSelectedOption(currentModule->moduleData.DisplayName);
    }

    modulesList->OnOpening.AddDynamic(this, &ThisClass::HandleOpened);
    modulesList->OnSelectionChanged.AddDynamic(this, &ThisClass::HandleSelectionChanged);
}

void USlotWidget::SetVisible(bool bVisible)
{
    ESlateVisibility newVis = bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed;
    modulesList->SetVisibility(newVis);
}

UWidget *USlotWidget::GenerateContentWidget(FName Item)
{
    UTextBlock *textBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
    textBlock->SetFont(_contentFont);
    textBlock->SetColorAndOpacity(_contentFontColor);
    textBlock->SetText(FText::FromName(Item));
    return textBlock;
}

UWidget *USlotWidget::GenerateItemWidget(FName Item)
{
    UTextBlock *textBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
    textBlock->SetFont(_optionFont);
    textBlock->SetColorAndOpacity(_optionFontColor);
    textBlock->SetText(FText::FromName(Item));
    return textBlock;
}

void USlotWidget::SetAttachmentsManager(UWeaponAttachmentsManager *inManager)
{
    attachmentsManager = inManager;
}

void USlotWidget::SetSlotData(FAttachmentSlot inSlotData)
{
    slotData = inSlotData;
}

void USlotWidget::HandleOpened()
{
    OnOpened.Broadcast(this);
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
