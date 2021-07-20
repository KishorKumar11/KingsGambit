// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "KingsIndianDefenceUserWidget.generated.h"

class UButton;
class UTextBlock;
class ATrainerController;

/**
  * Inherits from PauseMenuUserWidget because pause menu elements remain the same
  */
UCLASS()
class KINGSGAMBIT_API UKingsIndianDefenceUserWidget : public UPauseMenuUserWidget
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
		void StepPVToSelectVariationClicked();

	UFUNCTION()
		void StepSVToSelectVariationClicked();

	UFUNCTION()
		void StepFPAToSelectVariationClicked();

	UFUNCTION()
		void StepPetrosianVariationClicked();

	UFUNCTION()
		void StepSamischVariationClicked();

	UFUNCTION()
		void StepFourPawnsAttackClicked();

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
		UButton* StepPetrosianVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFourPawnsAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSamischVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepPVToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSVToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFPAToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSelectVariationToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepVariationToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* ExplanationPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* KIDBasic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* PetrosianVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SamischVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* FourPawnsAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* PV_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* PV_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* PV_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* SV_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* SV_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* SV_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* FPA_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* FPA_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* FPA_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* KIDBG_Variation;

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
		UTextBlock* StepPVTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepPV1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepSVTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepSV1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepFPATxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepFPA1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* SelectVariationTxt;
};
