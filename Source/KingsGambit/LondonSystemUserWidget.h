// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "LondonSystemUserWidget.generated.h"

class UButton;
class UTextBlock;
class ATrainerController;

/**
  * Inherits from PauseMenuUserWidget because pause menu elements remain the same
  */
UCLASS()
class KINGSGAMBIT_API ULondonSystemUserWidget : public UPauseMenuUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	ATrainerController* TrainerController;

protected:
	virtual void PauseButtonClicked();

	virtual void ResumeButtonClicked();

	virtual void MainMenuButtonClicked();

	virtual void QuitButtonClicked();

	UFUNCTION()
		void StepZeroToOneClicked();

	UFUNCTION()
		void StepOneToZeroClicked();

	UFUNCTION()
		void StepOneToTwoClicked();

	UFUNCTION()
		void StepTwoToOneClicked();

	UFUNCTION()
		void StepTwoToThreeClicked();

	UFUNCTION()
		void StepThreeToTwoClicked();

	UFUNCTION()
		void StepThreeToSelect_VariationClicked();

	UFUNCTION()
		void StepSelectVariationToThreeClicked();

	UFUNCTION()
		void Stepg6ToSelectVariationClicked();

	UFUNCTION()
		void Stepe6c5ToSelectVariationClicked();

	UFUNCTION()
		void Stepe6ToSelectVariationClicked();

	UFUNCTION()
		void Stepg6Clicked();

	UFUNCTION()
		void Stepe6c5Clicked();

	UFUNCTION()
		void Stepe6Clicked();

	UFUNCTION()
		void Stepg6WP1Clicked();

	UFUNCTION()
		void Stepg6WP1ToBackClicked();

	UFUNCTION()
		void Stepg6WP2Clicked();

	UFUNCTION()
		void Stepg6WP2ToBackClicked();

	UFUNCTION()
		void Stepg6BP1Clicked();

	UFUNCTION()
		void Stepg6BP1ToBackClicked();

	UFUNCTION()
		void Stepg6BP2Clicked();

	UFUNCTION()
		void Stepg6BP2ToBackClicked();

	UFUNCTION()
		void Stepg6ToSelectVariationClicked();

	UFUNCTION()
		void Stepe6c5WP1Clicked();

	UFUNCTION()
		void Stepe6c5WP1ToBackClicked();

	UFUNCTION()
		void Stepe6c5WP2Clicked();

	UFUNCTION()
		void Stepe6c5WP2ToBackClicked();

	UFUNCTION()
		void Stepe6c5BP1Clicked();

	UFUNCTION()
		void Stepe6c5BP1ToBackClicked();

	UFUNCTION()
		void Stepe6c5BP2Clicked();

	UFUNCTION()
		void Stepe6c5BP2ToBackClicked();

	UFUNCTION()
		void Stepe6c5ToSelectVariationClicked();

	UFUNCTION()
		void Stepe6WP1Clicked();

	UFUNCTION()
		void Stepe6WP1ToBackClicked();

	UFUNCTION()
		void Stepe6WP2Clicked();

	UFUNCTION()
		void Stepe6WP2ToBackClicked();

	UFUNCTION()
		void Stepe6BP1Clicked();

	UFUNCTION()
		void Stepe6BP1ToBackClicked();

	UFUNCTION()
		void Stepe6BP2Clicked();

	UFUNCTION()
		void Stepe6BP2ToBackClicked();

	UFUNCTION()
		void Stepe6ToSelectVariationClicked();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepZeroToOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepOneToZero;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepOneToTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepTwoToOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepTwoToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepThreeToTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepThreeToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6Variation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6Variation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5Variation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* g6ToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6WP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6WP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6WP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6WP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6BP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6BP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6BP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepg6BP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5WP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5WP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5WP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5WP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5BP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5BP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5BP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6c5BP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6WP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6WP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6WP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6WP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6BP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6BP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6BP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Stepe6BP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSelectVariationToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepVariationToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* ExplanationPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* LondonSystemBasic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Withg6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Withe6c5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Withe6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* g6_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* g6_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* g6_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6c5_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6c5_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6c5_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* e6_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepZeroTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepOneTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTwoTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepThreeTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepg6Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepg61Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepe6c5Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepe6c51Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepe6Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Stepe61Txt;
};