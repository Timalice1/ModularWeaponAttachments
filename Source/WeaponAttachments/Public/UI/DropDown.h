#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/ComboBoxKey.h"
#include "DropDown.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API UDropDown : public UUserWidget
{
    GENERATED_BODY()

    UFUNCTION()
    virtual void HandleOpening();
    UFUNCTION()
    virtual void HandleSelectionChanged(FName SelectedItem, ESelectInfo::Type SelectionType);
    FTimerHandle _closingTimer;

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHoveredSignature);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnhoveredSignature);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpeningEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosingEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectionChangedEvent, FName, SelectedItem, ESelectInfo::Type, SelectionType);

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UComboBoxKey> comboBox = nullptr;

protected:
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

    virtual void NativeOnMouseEnter(const FGeometry &InGeometry, const FPointerEvent &InMouseEvent) override;
    virtual void NativeOnMouseLeave(const FPointerEvent &InMouseEvent) override;

    UFUNCTION(BlueprintCallable, Category = DropDown)
    UWidget *GenerateContentWidget(FName Item);
    UFUNCTION(BlueprintCallable, Category = DropDown)
    UWidget *GenerateItemWidget(FName Item);

public:
    UFUNCTION()
    virtual UComboBoxKey *GetComboBox() { return comboBox; }

    UPROPERTY(EditAnywhere, Category = "Style|Content", meta = (DisplayName = "Font"))
    FSlateFontInfo _contentFont;
    UPROPERTY(EditAnywhere, Category = "Style|Content", meta = (DisplayName = "FontColor"))
    FSlateColor _contentFontColor;

    UPROPERTY(EditAnywhere, Category = "Style|Option", meta = (DisplayName = "Font"))
    FSlateFontInfo _optionFont;
    UPROPERTY(EditAnywhere, Category = "Style|Option", meta = (DisplayName = "FontColor"))
    FSlateColor _optionFontColor;

    UPROPERTY(EditAnywhere, Category = Style)
    bool bHasDownArrow = false;

public:
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnHoveredSignature OnHovered;
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnUnhoveredSignature OnUnhovered;
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnOpeningEvent OnOpening;
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnClosingEvent OnClosing;
    UPROPERTY(BlueprintAssignable, Category = Events)
    FOnSelectionChangedEvent OnSelectionChanged;
};
