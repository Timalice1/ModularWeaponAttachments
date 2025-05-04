#include "UI/DropDown.h"
#include "Components/TextBlock.h"

void UDropDown::NativePreConstruct()
{
    Super::NativePreConstruct();

    _optionFontColor = FLinearColor::White;
    _contentFontColor = FLinearColor::White;
}

void UDropDown::NativeConstruct()
{
    Super::NativeConstruct();
    comboBox->OnOpening.AddDynamic(this, &ThisClass::HandleOpening);
    comboBox->OnSelectionChanged.AddDynamic(this, &ThisClass::HandleSelectionChanged);
}

void UDropDown::NativeOnMouseEnter(const FGeometry &InGeometry, const FPointerEvent &InMouseEvent)
{
    Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
    OnHovered.Broadcast();
}

void UDropDown::NativeOnMouseLeave(const FPointerEvent &InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);
    OnUnhovered.Broadcast();
}

UWidget *UDropDown::GenerateContentWidget(FName Item)
{
    UTextBlock *textBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
    textBlock->SetFont(_contentFont);
    textBlock->SetColorAndOpacity(_contentFontColor);
    textBlock->SetText(FText::FromName(Item));
    return textBlock;
}

UWidget *UDropDown::GenerateItemWidget(FName Item)
{
    UTextBlock *textBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
    textBlock->SetFont(_optionFont);
    textBlock->SetColorAndOpacity(_optionFontColor);
    textBlock->SetText(FText::FromName(Item));
    return textBlock;
}

void UDropDown::HandleOpening()
{
    OnOpening.Broadcast();
    GetWorld()->GetTimerManager().SetTimer(
        _closingTimer,
        [this]()
        {
            if (!comboBox->IsOpen())
            {
                OnClosing.Broadcast();
                GetWorld()->GetTimerManager().ClearTimer(_closingTimer);
            }
        },
        0.1f, // Check every 100ms
        true  // Loop until closed
    );
}

void UDropDown::HandleSelectionChanged(FName SelectedItem, ESelectInfo::Type SelectionType)
{
    OnSelectionChanged.Broadcast(SelectedItem, SelectionType);
}