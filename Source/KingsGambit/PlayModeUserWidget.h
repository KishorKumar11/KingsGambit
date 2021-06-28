// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "PlayModeUserWidget.generated.h"

class UButton;
class UTextBlock;
class APlayModeController;

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API UPlayModeUserWidget : public UPauseMenuUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry,
		float InDeltaTime) override;

	APlayModeController* PlayModeController;

	UFUNCTION()
	void SetButtonVisibility(bool status);

	//Implemented in blueprints
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayErrorMessage();


protected:
		virtual void PauseButtonClicked();

		virtual void ResumeButtonClicked();

		virtual void MainMenuButtonClicked();

		virtual void QuitButtonClicked();

		UFUNCTION()
		void ConfirmMoveButtonClicked();

		UFUNCTION()
		void CancelMoveButtonClicked();

		UFUNCTION()
		void OKButtonClicked();

		UFUNCTION(BlueprintCallable)
		FText GetCurrentPlayerName();

		UFUNCTION(BlueprintCallable)
		FText GetErrorMessage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* ConfirmMoveWrapper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UBorder* UserGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UVerticalBox* UserGuideInterface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ConfirmMoveButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* CancelMoveButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* OKButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ErrorMessage;
};
