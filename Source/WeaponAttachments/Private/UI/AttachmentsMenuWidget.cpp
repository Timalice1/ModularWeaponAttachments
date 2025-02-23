#include "UI/AttachmentsMenuWidget.h"
#include "UI/AttachmentsMenuButton.h"
#include "UI/AttachmentsPanel.h"
#include "WeaponAttachmentsManager.h"
#include "AttachmentSlot.h"
#include "Components/VerticalBox.h"
#include "Components/Overlay.h"

void UAttachmentsMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!attachmentsComponentRef)
        return;
    UpdateMenu();
}

void UAttachmentsMenuWidget::UpdateMenu()
{
    if (!panelTemplate || !slotButtonTemplate)
        return;

    // Clear containers at start
    slotsList->ClearChildren();
    panelsContainer->ClearChildren();
    _buttonToPanelMap.Empty();

    for (FAttachmentSlot &activeSlot : attachmentsComponentRef->GetActiveSlots())
    {
        FText _label = FText::FromName(activeSlot.SlotName);

        UAttachmentsMenuButton *newSlotButton = NewObject<UAttachmentsMenuButton>(this, slotButtonTemplate);
        UAttachmentsPanel *newPanel = NewObject<UAttachmentsPanel>(this, panelTemplate);
        if (!newSlotButton || !newPanel)
            continue;

        newSlotButton->buttonLabelText = _label;
        newPanel->panelLabel_Text = _label;
        newPanel->SlotType = activeSlot.slotType;
        newPanel->SetVisibility(ESlateVisibility::Collapsed);

        slotsList->AddChild(newSlotButton);
        panelsContainer->AddChild(newPanel);

        _buttonToPanelMap.Add(newSlotButton, newPanel);
        newSlotButton->OnClick.AddDynamic(this, &ThisClass::TogglePanel);
    }
}

void UAttachmentsMenuWidget::TogglePanel(UAttachmentsMenuButton *slotButton)
{
    // Hide current active panel
    if (currentActivePanel)
        currentActivePanel->SetVisibility(ESlateVisibility::Collapsed);

    UAttachmentsPanel *targetPanel = *_buttonToPanelMap.Find(slotButton);
    if (!targetPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("AttachmentsMenuWidget::TooglePanel - Requested panel not found"));
        return;
    }

    // Just close active panel if requested same panel
    if (targetPanel == currentActivePanel)
    {
        currentActivePanel = nullptr;
        return;
    }

    currentActivePanel = targetPanel;
    currentActivePanel->SetAttachmentsManager(attachmentsComponentRef);
    currentActivePanel->UpdatePanel();
    currentActivePanel->SetVisibility(ESlateVisibility::Visible);
}
