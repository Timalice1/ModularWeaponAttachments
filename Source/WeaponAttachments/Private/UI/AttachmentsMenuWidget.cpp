#include "UI/AttachmentsMenuWidget.h"
#include "UI/SlotWidget.h"
#include "Components/WidgetComponent.h"
#include "WeaponAttachmentsManager.h"

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
    // Clear containers at start
    ClearSlotsWidgets();

    for (FAttachmentSlot &activeSlot : attachmentsComponentRef->GetActiveSlots())
    {
        /*Instantiate new slot widget*/
        TObjectPtr<USlotWidget> newSlotWidget = CreateWidget<USlotWidget>(this, SlotWidgetTemplate);
        if (!newSlotWidget)
            return;

        newSlotWidget->SetVisible(true);
        newSlotWidget->SetAttachmentsManager(attachmentsComponentRef);
        newSlotWidget->SetSlotData(activeSlot);
        activeSlotWidgets.Add(newSlotWidget);

        /*Instantiate widget component*/
        FName _componentName = FName(*(activeSlot.SlotName.ToString() + TEXT("_WidgetComponent")));
        UWidgetComponent *slotWidget_Component = NewObject<UWidgetComponent>(
            attachmentsComponentRef->GetOwner(),
            UWidgetComponent::StaticClass(),
            _componentName);

        if (slotWidget_Component)
        {
            slotWidget_Component->AttachToComponent(activeSlot.parent, FAttachmentTransformRules::SnapToTargetIncludingScale, activeSlot.SocketName);
            slotWidget_Component->SetWidgetSpace(EWidgetSpace::Screen);
            slotWidget_Component->SetWidget(newSlotWidget);
            slotWidget_Component->SetDrawAtDesiredSize(true);
            slotWidget_Component->SetPivot(newSlotWidget->pivotPoint);
            slotWidget_Component->RegisterComponent();
            slotWidget_Components.AddUnique(slotWidget_Component);
        }

        newSlotWidget->OnOpened.AddDynamic(this, &ThisClass::OnMenuOpened);
        newSlotWidget->OnSelectionChanged.AddDynamic(this, &ThisClass::OnModuleSelectionChanged);
    }
}

void UAttachmentsMenuWidget::ClearSlotsWidgets()
{
    for (UWidgetComponent *slotWidget : slotWidget_Components)
        slotWidget->DestroyComponent(true);
    slotWidget_Components.Empty();
    activeSlotWidgets.Empty();
}

void UAttachmentsMenuWidget::OnMenuOpened(USlotWidget *slotWidget)
{
}

void UAttachmentsMenuWidget::OnModuleSelectionChanged(FName Item)
{
    UpdateMenu();
}