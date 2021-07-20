// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "ItalianGameUserWidget.generated.h"

class UButton;
class UTextBlock;
class ATrainerController;

/**
  * Inherits from PauseMenuUserWidget because pause menu elements remain the same
  */
UCLASS()
class KINGSGAMBIT_API UItalianGameUserWidget : public UPauseMenuUserWidget
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
		void GiuocoVariationClicked();

	UFUNCTION()
		void TwoKnightsDefenseVariationClicked();

	UFUNCTION()
		void HungarianDefenseVariationClicked();

	UFUNCTION()
		void StepGPToSelectVariationClicked();

	UFUNCTION()
		void StepTKDToSelectVariationClicked();

	UFUNCTION()
		void StepHDToSelectVariationClicked();

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
		UButton* StepThreeToSelect_Variation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* GiuocoPianoVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* TwoKnightsDefenseVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* HungarianDefenseVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepGPToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepTKDToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepHDToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSelectVariationToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepVariationToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* ExplanationPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* ItalianGameBasic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* GiuocoPiano;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* TwoKnightsDefense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* HungarianDefense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* GP_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* GP_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* GP_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* TKD_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* TKD_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* TKD_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* HD_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* HD_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* HD_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* IGBG_Variation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UBackgroundBlur* BackgroundBlur_0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UBackgroundBlur* BackgroundBlur;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UBackgroundBlur* BackgroundBlur_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UBackgroundBlur* BackgroundBlur_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepZeroTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepOneTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTwoTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepThreeTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepGPTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepGP1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTKDTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTKD1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepHDTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepHD1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* SelectVariationTxt;
};
