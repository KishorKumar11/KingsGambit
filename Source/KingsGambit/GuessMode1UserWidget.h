//King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "GuessMode1UserWidget.generated.h"

class UButton;
class UBorder;
class UTextBlock;
class UImage;
class UCanvasPanel;

/**
 * Inherits from PauseMenuUserWidget because pause menu elements remain the same
 */
UCLASS()
class KINGSGAMBIT_API UGuessMode1UserWidget : public UPauseMenuUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	class ATrainerController* TrainerController;

protected:
	virtual void PauseButtonClicked();

	virtual void ResumeButtonClicked();

	virtual void MainMenuButtonClicked();

	virtual void QuitButtonClicked();

	UFUNCTION()
		void OKToNotationsModeClicked();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* OKToNotationsMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Enter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* TryAgain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* GameOverToMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UBorder* UserGuide_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UBorder* GameOverHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UVerticalBox* UserGuideInterface_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Leveltxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Attemptstxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* LevelNo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* AttemptsNo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Correct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Wrong;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UEditableTextBox* Answer1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* GuessModeHUD;

};