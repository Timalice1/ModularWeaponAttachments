#include "UI/SlotButton.h"
#include "Components/Button.h"
#include "Components/Image.h"

void USlotButton::SetVisible(bool bVisible)
{
    if (bVisible)
        button->SetVisibility(ESlateVisibility::Visible);
    else
        button->SetVisibility(ESlateVisibility::Collapsed);
}