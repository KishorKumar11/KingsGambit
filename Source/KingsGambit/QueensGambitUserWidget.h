// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "PauseMenuUserWidget.h"
#include "QueensGambitUserWidget.generated.h"

class UButton;
class UTextBlock;
class UCanvasPanel;
class ATrainerController;

/**
  * Inherits from PauseMenuUserWidget because pause menu elements remain the same
  */
UCLASS()
class KINGSGAMBIT_API UQueensGambitUserWidget : public UPauseMenuUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	ATrainerController* TrainerController;

protected:
	/********** Inherited Functions for pause **************/
	virtual void PauseButtonClicked();

	virtual void ResumeButtonClicked();

	virtual void MainMenuButtonClicked();

	virtual void QuitButtonClicked();

	/********** Functions for basic queen's gambit **************/
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

	/********** Functions for Select Variation Screen **************/
	UFUNCTION()
		void Step3ToSelectVariationClicked();

	UFUNCTION()
		void SelectVariationToStep3Clicked();

	UFUNCTION()
		void StepSlavDefencetoStepFourClicked();

	UFUNCTION()
		void StepQueensGambitDeclinedtoStep12Clicked();

	UFUNCTION()
		void StepQueensGambitAcceptedtoStep20Clicked();

	/********** Functions for Slav Defence **************/
	UFUNCTION()
		void StepFourToSelectVariationClicked();

	UFUNCTION()
		void StepFourToFiveClicked();

	UFUNCTION()
		void StepFiveToFourClicked();

	UFUNCTION()
		void StepFiveToSixClicked();

	UFUNCTION()
		void StepSixToFiveClicked();

	UFUNCTION()
		void StepSixToSevenClicked();

	UFUNCTION()
		void StepSevenToSixClicked();

	UFUNCTION()
		void StepSevenToEightClicked();

	UFUNCTION()
		void StepEightToSevenClicked();

	UFUNCTION()
		void StepEightToNineClicked();

	UFUNCTION()
		void StepNineToEightClicked();

	UFUNCTION()
		void StepNineToTenClicked();

	UFUNCTION()
		void StepTenToNineClicked();

	UFUNCTION()
		void StepTenTo11Clicked();

	UFUNCTION()
		void Step11ToTenClicked();

	UFUNCTION()
		void Step11ToSelectVariationClicked();

	/********** Functions for Queen's Gambit Declined **************/
	UFUNCTION()
		void Step12ToSelectVariationClicked();

	UFUNCTION()
		void Step12To13Clicked();

	UFUNCTION()
		void Step13To12Clicked();

	UFUNCTION()
		void Step13To14Clicked();

	UFUNCTION()
		void Step14To13Clicked();

	UFUNCTION()
		void Step14To15Clicked();

	UFUNCTION()
		void Step15To14Clicked();

	UFUNCTION()
		void Step15To16Clicked();

	UFUNCTION()
		void Step16To15Clicked();

	UFUNCTION()
		void Step16To17Clicked();

	UFUNCTION()
		void Step17To16Clicked();

	UFUNCTION()
		void Step17To18Clicked();

	UFUNCTION()
		void Step18To17Clicked();

	UFUNCTION()
		void Step18ToSelectVariationClicked();

	/********** Functions for Queen's Gambit Accepted **************/
	UFUNCTION()
		void Step20ToSelectVariationClicked();

	UFUNCTION()
		void Step20To21Clicked();

	UFUNCTION()
		void Step21To20Clicked();

	UFUNCTION()
		void Step21To22Clicked();

	UFUNCTION()
		void Step22To21Clicked();

	UFUNCTION()
		void Step22To23Clicked();

	UFUNCTION()
		void Step23To22Clicked();

	UFUNCTION()
		void Step23To24Clicked();

	UFUNCTION()
		void Step24To23Clicked();

	UFUNCTION()
		void Step24To25Clicked();

	UFUNCTION()
		void Step25To24Clicked();

	UFUNCTION()
		void Step25To26Clicked();

	UFUNCTION()
		void Step26To25Clicked();

	UFUNCTION()
		void Step26To27Clicked();

	UFUNCTION()
		void Step27To26Clicked();

	UFUNCTION()
		void Step27ToSelectVariationClicked();


	/********** Queen's Gambit Basic Buttons **************/
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
		UButton* StepThreeToSelectVariation;

	/********** Variation Screen Buttons **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSelectVariationToThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepVariationToMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSlavDefencetoStepFour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepQueensGambitDeclinedtoStep12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepQueensGambitAcceptedtoStep20;

	/********** Slav Defence Buttons **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFourToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFourToFive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFiveToFour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepFiveToSix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSixToFive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSixToSeven;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSevenToSix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepSevenToEight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepEightToSeven;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepEightToNine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNineToEight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepNineToTen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepTenToNine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* StepTenTo11;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step11ToTen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step11ToSelectVariation;

	/********** Queen's Gambit Declined Buttons **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step12ToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step12To13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step13To12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step13To14;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step14To13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step14To15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step15To14;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step15To16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step16To15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step16To17;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step17To16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step17To18;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step18To17;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step18ToSelectVariation;

	/********** Queen's Gambit Accepted Buttons **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step20ToSelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step20To21;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step21To20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step21To22;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step22To21;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step22To23;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step23To22;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step23To24;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step24To23;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step24To25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step25To24;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step25To26;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step26To25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step26To27;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step27To26;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* Step27ToSelectVariation;

	/********** Panels **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* ExplanationPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* QueensGambitBasic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* SelectVariation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* SlavDefence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* QueensGambitDeclined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UCanvasPanel* QueensGambitAccepted;

	/********** Text blocks **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepZeroTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepOneTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTwoTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepThreeTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* SelectVariationTxt;

	/********** Text blocks for Slave Defence **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepFourTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepFiveTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepSixTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepSevenTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepEightTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepNineTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* StepTenTxt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step11Txt;

	/********** Text blocks for Queens Gambit Declined **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step12Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step13Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step14Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step15Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step16Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step17Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step18Txt;

	/********** Text blocks for Queens Gambit Accepted **************/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step20Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step21Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step22Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step23Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step24Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step25Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step26Txt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* Step27Txt;
};