 //King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "GuessModeUserWidget.generated.h"

class UButton;
class UBorder;
class UTextBlock;
class UImage;
class UCanvasPanel;

/**
 * Inherits from PauseMenuUserWidget because pause menu elements remain the same
 */
UCLASS()
class KINGSGAMBIT_API UGuessModeUserWidget : public UPauseMenuUserWidget
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
		void OKToMovesModeClicked();

	UFUNCTION()
		void OKToMovesMode1Clicked();

	UFUNCTION()
		void ManualButtonClicked();

	UFUNCTION(BlueprintCallable)
		void ResetLevels();

	UFUNCTION(BlueprintCallable)
		void SetLevel(int32 level);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ManualButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* OKToMovesMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* OKToMovesMode_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* GameOverToMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* YouWonToMenu_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UBorder* UserGuide_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UBorder* UserGuide_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* GuessModeHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* Lvl1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* Lvl2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* Lvl3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* Lvl4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* Lvl5;

};