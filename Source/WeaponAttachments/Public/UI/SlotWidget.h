#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachmentSlot.h"
#include "SlotWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenedEvent, class USlotWidget *, slotWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionChangedEvent, FName, Item);

UCLASS()
class WEAPONATTACHMENTS_API USlotWidget : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsManager;

    /**
     * @todo Replace with FName
     */
    FAttachmentSlot slotData;
    TArray<struct FAttachmentModuleData> compatibleAttachments;

    UFUNCTION()
    void HandleOpened();
    UFUNCTION()
    void HandleSelectionChanged(FName SelectedItem, ESelectInfo::Type SelectionType);

public:
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

    virtual void SetVisible(bool bVisible = true);

    virtual void SetAttachmentsManager(class UWeaponAttachmentsManager *inManager);
    virtual void SetSlotData(FAttachmentSlot inSlotData);

    UPROPERTY(BlueprintCallable, Category = SlotWidget)
    FOnOpenedEvent OnOpened;
    UPROPERTY(BlueprintCallable, Category = SlotWidget)
    FOnSelectionChangedEvent OnSelectionChanged;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = SlotWidget)
    FVector2D pivotPoint = FVector2D(.5, .5);

protected: // Widgets
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<class UImage> slotMarker;
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UComboBoxKey> modulesList;

protected: // Styling
    UPROPERTY(EditDefaultsOnly, Category = "ComboBoxKey|Style|Content", meta = (DisplayName = "Font"))
    FSlateFontInfo _contentFont;
    UPROPERTY(EditDefaultsOnly, Category = "ComboBoxKey|Style|Content", meta = (DisplayName = "FontColor"))
    FSlateColor _contentFontColor;

    UPROPERTY(EditDefaultsOnly, Category = "ComboBoxKey|Style|Option", meta = (DisplayName = "Font"))
    FSlateFontInfo _optionFont;
    UPROPERTY(EditDefaultsOnly, Category = "ComboBoxKey|Style|Option", meta = (DisplayName = "FontColor"))
    FSlateColor _optionFontColor;

protected:
    UFUNCTION(BlueprintCallable, Category = SlotWidget)
    UWidget *GenerateContentWidget(FName Item);
    UFUNCTION(BlueprintCallable, Category = SlotWidget)
    UWidget *GenerateItemWidget(FName Item);
};