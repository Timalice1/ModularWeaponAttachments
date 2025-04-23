#include "UI/AttachmentsMenuWidget.h"
#include "UI/AttachmentsPanel.h"
#include "UI/SlotButton.h"
#include "Components/VerticalBox.h"
#include "Components/Overlay.h"
#include "Components/WidgetComponent.h"
#include "WeaponAttachmentsManager.h"
#include "AttachmentSlot.h"

void UAttachmentsMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (!attachmentsComponentRef)
        return;
    UpdateMenu();
}

void UAttachmentsMenuWidget::NativeDestruct()
{
    Super::NativeDestruct();
    ClearSlotsWidgets();
}

void UAttachmentsMenuWidget::UpdateMenu()
{
    if (!panelTemplate || !slotButtonTemplate)
        return;

    // Clear containers at start
    ClearSlotsWidgets();
    panelsContainer->ClearChildren();
    _buttonToPanelMap.Empty();
    slotButtons.Empty();

    for (FAttachmentSlot &activeSlot : attachmentsComponentRef->GetActiveSlots())
    {
        FText _label = FText::FromName(activeSlot.SlotName);
        FName _componentName = FName(*(activeSlot.SlotName.ToString() + TEXT("_Widget")));

        USlotButton *newSlotButton = NewObject<USlotButton>(this, slotButtonTemplate);
        UAttachmentsPanel *newPanel = NewObject<UAttachmentsPanel>(this, panelTemplate);
        if (!newSlotButton || !newPanel)
            continue;

        newSlotButton->buttonLabelText = _label;
        /*Populate widgets on weapon mesh*/
        UWidgetComponent *slotWidget =
            NewObject<UWidgetComponent>(attachmentsComponentRef->GetOwner(), UWidgetComponent::StaticClass(), _componentName);
        slotWidget->AttachToComponent(activeSlot.parent, FAttachmentTransformRules::SnapToTargetIncludingScale, activeSlot.SocketName);
        slotWidget->SetWidgetSpace(EWidgetSpace::Screen);
        slotWidget->SetWidget(newSlotButton);
        slotWidget->SetDrawAtDesiredSize(true);
        slotWidget->SetPivot(newSlotButton->pivotPoint);
        slotWidget->RegisterComponent();
        slotWidgets.AddUnique(slotWidget);

        newSlotButton->SetVisible(true);
        slotButtons.Add(newSlotButton);

        newPanel->panelLabel_Text = _label;
        newPanel->slotData = activeSlot;
        newPanel->SetVisibility(ESlateVisibility::Collapsed);
        panelsContainer->AddChild(newPanel);

        newSlotButton->OnClick.AddDynamic(this, &ThisClass::TogglePanel);
        newPanel->OnModuleInstalled.AddDynamic(this, &ThisClass::UpdateMenu);
        _buttonToPanelMap.Add(newSlotButton, newPanel);
    }
}

void UAttachmentsMenuWidget::TogglePanel(UAttachmentsMenuButton *slotButton)
{
    // Hide current active panel
    if (currentActivePanel)
        currentActivePanel->SetVisibility(ESlateVisibility::Collapsed);

    for (USlotButton *slot : slotButtons)
    {
        if (slot != slotButton)
            slot->SetVisible(false);
    }

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
        UpdateMenu();
        return;
    }

    currentActivePanel = targetPanel;
    currentActivePanel->SetAttachmentsManager(attachmentsComponentRef);
    currentActivePanel->UpdatePanel();
    currentActivePanel->SetVisibility(ESlateVisibility::Visible);
}

void UAttachmentsMenuWidget::ClearSlotsWidgets()
{
    for (UWidgetComponent *slotWidget : slotWidgets)
        slotWidget->DestroyComponent(true);
    slotWidgets.Empty();
}