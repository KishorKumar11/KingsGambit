// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "SicilianDefenceUserWidget.generated.h"

class UButton;
class UTextBlock;
class ATrainerController;

/**
  * Inherits from PauseMenuUserWidget because pause menu elements remain the same
  */
UCLASS()
class KINGSGAMBIT_API USicilianDefenceUserWidget : public UPauseMenuUserWidget
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
		void StepThreeToVariationClicked();

	UFUNCTION()
		void StepThreeToVariationClicked();

	UFUNCTION()
		void StepSelectVariationToThreeClicked();

	UFUNCTION()
		void StepVariationToMainMenuClicked();

	UFUNCTION()
		void NajdorfVariationClicked();

	UFUNCTION()
		void DragonVariationClicked();

	UFUNCTION()
		void ClassicalVariationClicked();

	UFUNCTION()
		void StepNVWP1Clicked();

	UFUNCTION()
		void StepNVWP1ToBackClicked();

	UFUNCTION()
		void StepNVWP2Clicked();

	UFUNCTION()
		void StepNVWP2ToBackClicked();

	UFUNCTION()
		void StepNVWP3Clicked();

	UFUNCTION()
		void StepNVWP3ToBackClicked();

	UFUNCTION()
		void StepNVBP1Clicked();

	UFUNCTION()
		void StepNVBP1ToBackClicked();

	UFUNCTION()
		void StepNVBP2Clicked();

	UFUNCTION()
		void StepNVBP2ToBackClicked();

	UFUNCTION()
		void StepNVBP3Clicked();

	UFUNCTION()
		void StepNVBP3ToBackClicked();

	UFUNCTION()
		void StepNVToSelectVariationClicked();

	UFUNCTION()
		void StepDVWP1Clicked();

	UFUNCTION()
		void StepDVWP1ToBackClicked();

	UFUNCTION()
		void StepDVWP2Clicked();

	UFUNCTION()
		void StepDVWP2ToBackClicked();

	UFUNCTION()
		void StepDVWP3Clicked();

	UFUNCTION()
		void StepDVWP3ToBackClicked();

	UFUNCTION()
		void StepDVBP1Clicked();

	UFUNCTION()
		void StepDVBP1ToBackClicked();

	UFUNCTION()
		void StepDVBP2Clicked();

	UFUNCTION()
		void StepDVBP2ToBackClicked();

	UFUNCTION()
		void StepDVBP3Clicked();

	UFUNCTION()
		void StepDVBP3ToBackClicked();

	UFUNCTION()
		void StepDVBP4Clicked();

	UFUNCTION()
		void StepDVBP4ToBackClicked();

	UFUNCTION()
		void StepDVToSelectVariationClicked();

	UFUNCTION()
		void StepCVWP1Clicked();

	UFUNCTION()
		void StepCVWP1ToBackClicked();

	UFUNCTION()
		void StepCVWP2Clicked();

	UFUNCTION()
		void StepCVWP2ToBackClicked();

	UFUNCTION()
		void StepCVWP3Clicked();

	UFUNCTION()
		void StepCVWP3ToBackClicked();

	UFUNCTION()
		void StepCVWP4Clicked();

	UFUNCTION()
		void StepCVWP4ToBackClicked();

	UFUNCTION()
		void StepCVToSelectVariationClicked();

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
		UButton* NajdorfVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* DragonVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ClassicalVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* CVToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* NVToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* DVToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP3ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVWP4ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP3ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepCVBP4ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVWP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVWP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVWP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVWP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVBP3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVBP3ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVBP4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepDVBP4ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVWP3ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP1ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP2; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP2ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNVBP3ToBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSelectVariationToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepVariationToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* ExplanationPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SDBasic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* SelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Najdorf;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Dragon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* Classical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* NV_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* NV_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* NV_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* CV_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* CV_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* CV_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* DV_Main;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* DV_WHITEMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* DV_BLACKMOVES;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepZeroTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepOneTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTwoTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepThreeTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepNVTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepNV1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepDVTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepDV1Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepCVTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepCV1Txt;
};