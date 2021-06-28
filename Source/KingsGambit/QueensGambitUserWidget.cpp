// King's Gambit by Jonathan Mui and Kishor Kumar


#include "QueensGambitUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UQueensGambitUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	/********** Inherited Functions for pause **************/
	PauseButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::QuitButtonClicked);

	/********** Queen's Gambit Basic **************/
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepThreeToTwoClicked);
	StepThreeToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step3ToSelectVariationClicked);

	/********** Select Variation Buttons **************/
	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::SelectVariationToStep3Clicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::MainMenuButtonClicked);
	StepSlavDefencetoStepFour->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSlavDefencetoStepFourClicked);
	StepQueensGambitDeclinedtoStep12->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQueensGambitDeclinedtoStep12Clicked);
	StepQueensGambitAcceptedtoStep20->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQueensGambitAcceptedtoStep20Clicked);

	/********** Slav Defence Buttons **************/ 
	StepFourToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepFourToSelectVariationClicked);
	StepFourToFive->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepFourToFiveClicked);
	StepFiveToFour->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepFiveToFourClicked);
	StepFiveToSix->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepFiveToSixClicked);
	StepSixToFive->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSixToFiveClicked);
	StepSixToSeven->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSixToSevenClicked);
	StepSevenToSix->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSevenToSixClicked);
	StepSevenToEight->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSevenToEightClicked);
	StepEightToSeven->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepEightToSevenClicked);
	StepEightToNine->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepEightToNineClicked);
	StepNineToEight->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepNineToEightClicked);
	StepNineToTen->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepNineToTenClicked);
	StepTenToNine->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTenToNineClicked);
	StepTenTo11->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTenTo11Clicked);
	Step11ToTen->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step11ToTenClicked);
	Step11ToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step11ToSelectVariationClicked);

	/********** Queen's Gambit Declined Buttons **************/
	Step12ToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step12ToSelectVariationClicked);
	Step12To13->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step12To13Clicked);
	Step13To12->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step13To12Clicked);
	Step13To14->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step13To14Clicked);
	Step14To13->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step14To13Clicked);
	Step14To15->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step14To15Clicked);
	Step15To14->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step15To14Clicked);
	Step15To16->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step15To16Clicked);
	Step16To15->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step16To15Clicked);
	Step16To17->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step16To17Clicked);
	Step17To16->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step17To16Clicked);
	Step17To18->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step17To18Clicked);
	Step18To17->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step18To17Clicked);
	Step18ToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step18ToSelectVariationClicked);

	/********** Queen's Gambit Accepted Buttons **************/
	Step20ToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step20ToSelectVariationClicked);
	Step20To21->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step20To21Clicked);
	Step21To20->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step21To20Clicked);
	Step21To22->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step21To22Clicked);
	Step22To21->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step22To21Clicked);
	Step22To23->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step22To23Clicked);
	Step23To22->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step23To22Clicked);
	Step23To24->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step23To24Clicked);
	Step24To23->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step24To23Clicked);
	Step24To25->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step24To25Clicked);
	Step25To24->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step25To24Clicked);
	Step25To26->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step25To26Clicked);
	Step26To25->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step26To25Clicked);
	Step26To27->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step26To27Clicked);
	Step27To26->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step27To26Clicked);
	Step27ToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::Step27ToSelectVariationClicked);
}

/********** Inherited Functions for pause **************/
void UQueensGambitUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UQueensGambitUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

/********** Queen's Gambit Basic **************/
void UQueensGambitUserWidget::StepZeroToOneClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));
}

void UQueensGambitUserWidget::StepOneToZeroClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

 	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void UQueensGambitUserWidget::StepOneToTwoClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[2], FVector(1200.f, 800.f, 0.5f));
}

void UQueensGambitUserWidget::StepTwoToOneClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
}

void UQueensGambitUserWidget::StepTwoToThreeClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);


}

void UQueensGambitUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step3ToSelectVariationClicked() 
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	StepSlavDefencetoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitDeclinedtoStep12->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAcceptedtoStep20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::SelectVariationToStep3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Hidden);
}

/******************** Slav Defence ******************/
void UQueensGambitUserWidget::StepSlavDefencetoStepFourClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefence->SetVisibility(ESlateVisibility::Visible);
	
	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepFourTxt->SetVisibility(ESlateVisibility::Visible);
	StepFourToFive->SetVisibility(ESlateVisibility::Visible);

}

void UQueensGambitUserWidget::StepFourToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefence->SetVisibility(ESlateVisibility::Hidden);

	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	StepSlavDefencetoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitDeclinedtoStep12->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAcceptedtoStep20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepFourToFiveClicked()
{
	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	StepFourTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFourToFive->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Visible);
	StepFiveToFour->SetVisibility(ESlateVisibility::Visible);
	StepFiveToSix->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepFiveToFourClicked()
{
	StepFiveTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToFour->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToSix->SetVisibility(ESlateVisibility::Hidden);

	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepFourTxt->SetVisibility(ESlateVisibility::Visible);
	StepFourToFive->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepFiveToSixClicked()
{
	StepFiveTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToFour->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToSix->SetVisibility(ESlateVisibility::Hidden);

	StepSixTxt->SetVisibility(ESlateVisibility::Visible);
	StepSixToFive->SetVisibility(ESlateVisibility::Visible);
	StepSixToSeven->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepSixToFiveClicked()
{
	StepSixTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSixToFive->SetVisibility(ESlateVisibility::Hidden);
	StepSixToSeven->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Visible);
	StepFiveToFour->SetVisibility(ESlateVisibility::Visible);
	StepFiveToSix->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepSixToSevenClicked()
{
	StepSevenTxt->SetVisibility(ESlateVisibility::Visible);
	StepSevenToSix->SetVisibility(ESlateVisibility::Visible);
	StepSevenToEight->SetVisibility(ESlateVisibility::Visible);

	StepSixTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSixToFive->SetVisibility(ESlateVisibility::Hidden);
	StepSixToSeven->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSevenToSixClicked()
{
	StepSixTxt->SetVisibility(ESlateVisibility::Visible);
	StepSixToFive->SetVisibility(ESlateVisibility::Visible);
	StepSixToSeven->SetVisibility(ESlateVisibility::Visible);

	StepSevenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToSix->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToEight->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSevenToEightClicked()
{
	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepSevenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToSix->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToEight->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepEightToSevenClicked()
{
	StepSevenTxt->SetVisibility(ESlateVisibility::Visible);
	StepSevenToSix->SetVisibility(ESlateVisibility::Visible);
	StepSevenToEight->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepEightToNineClicked()
{
	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepNineToEightClicked()
{
	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepNineToTenClicked()
{
	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepTenToNineClicked()
{
	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepTenTo11Clicked()
{
	Step11Txt->SetVisibility(ESlateVisibility::Visible);
	Step11ToTen->SetVisibility(ESlateVisibility::Visible);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step11ToTenClicked()
{
	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step11ToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefence->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

/******************** Queen's Gambit Declined ******************/
void UQueensGambitUserWidget::StepQueensGambitDeclinedtoStep12Clicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitDeclined->SetVisibility(ESlateVisibility::Visible);

	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step12Txt->SetVisibility(ESlateVisibility::Visible);
	Step12To13->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step12ToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	QueensGambitDeclined->SetVisibility(ESlateVisibility::Hidden);

	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step12Txt->SetVisibility(ESlateVisibility::Hidden);
	Step12To13->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step12To13Clicked()
{
	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step12Txt->SetVisibility(ESlateVisibility::Hidden);
	Step12To13->SetVisibility(ESlateVisibility::Hidden);

	Step13Txt->SetVisibility(ESlateVisibility::Visible);
	Step13To12->SetVisibility(ESlateVisibility::Visible);
	Step13To14->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step13To12Clicked()
{
	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step12Txt->SetVisibility(ESlateVisibility::Visible);
	Step12To13->SetVisibility(ESlateVisibility::Visible);

	Step13Txt->SetVisibility(ESlateVisibility::Hidden);
	Step13To12->SetVisibility(ESlateVisibility::Hidden);
	Step13To14->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step13To14Clicked()
{
	Step13Txt->SetVisibility(ESlateVisibility::Hidden);
	Step13To12->SetVisibility(ESlateVisibility::Hidden);
	Step13To14->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step14To13Clicked()
{
	Step13Txt->SetVisibility(ESlateVisibility::Visible);
	Step13To12->SetVisibility(ESlateVisibility::Visible);
	Step13To14->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step14To15Clicked()
{
	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step15To14Clicked()
{
	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step15To16Clicked()
{
	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step16To15Clicked()
{
	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step16To17Clicked()
{
	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step17To16Clicked()
{
	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step17To18Clicked()
{
	Step18Txt->SetVisibility(ESlateVisibility::Visible);
	Step18ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step18To17->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step18To17Clicked()
{
	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step18Txt->SetVisibility(ESlateVisibility::Hidden);
	Step18ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step18To17->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step18ToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	QueensGambitDeclined->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	Step18Txt->SetVisibility(ESlateVisibility::Hidden);
	Step18ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step18To17->SetVisibility(ESlateVisibility::Hidden);
}

/******************** Queen's Gambit Accepted ******************/
void UQueensGambitUserWidget::StepQueensGambitAcceptedtoStep20Clicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step20Txt->SetVisibility(ESlateVisibility::Visible);
	Step20To21->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step20ToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step20Txt->SetVisibility(ESlateVisibility::Hidden);
	Step20To21->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step20To21Clicked()
{
	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step20Txt->SetVisibility(ESlateVisibility::Hidden);
	Step20To21->SetVisibility(ESlateVisibility::Hidden);

	Step21Txt->SetVisibility(ESlateVisibility::Visible);
	Step21To20->SetVisibility(ESlateVisibility::Visible);
	Step21To22->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step21To20Clicked()
{
	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step20Txt->SetVisibility(ESlateVisibility::Visible);
	Step20To21->SetVisibility(ESlateVisibility::Visible);

	Step21Txt->SetVisibility(ESlateVisibility::Hidden);
	Step21To20->SetVisibility(ESlateVisibility::Hidden);
	Step21To22->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step21To22Clicked()
{
	Step22Txt->SetVisibility(ESlateVisibility::Visible);
	Step22To21->SetVisibility(ESlateVisibility::Visible);
	Step22To23->SetVisibility(ESlateVisibility::Visible);

	Step21Txt->SetVisibility(ESlateVisibility::Hidden);
	Step21To20->SetVisibility(ESlateVisibility::Hidden);
	Step21To22->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step22To21Clicked()
{
	Step22Txt->SetVisibility(ESlateVisibility::Hidden);
	Step22To21->SetVisibility(ESlateVisibility::Hidden);
	Step22To23->SetVisibility(ESlateVisibility::Hidden);

	Step21Txt->SetVisibility(ESlateVisibility::Visible);
	Step21To20->SetVisibility(ESlateVisibility::Visible);
	Step21To22->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::Step22To23Clicked()
{
	Step23Txt->SetVisibility(ESlateVisibility::Visible);
	Step23To22->SetVisibility(ESlateVisibility::Visible);
	Step23To24->SetVisibility(ESlateVisibility::Visible);

	Step22Txt->SetVisibility(ESlateVisibility::Hidden);
	Step22To21->SetVisibility(ESlateVisibility::Hidden);
	Step22To23->SetVisibility(ESlateVisibility::Hidden);

}

void UQueensGambitUserWidget::Step23To22Clicked()
{
	Step22Txt->SetVisibility(ESlateVisibility::Visible);
	Step22To21->SetVisibility(ESlateVisibility::Visible);
	Step22To23->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Hidden);
	Step23To22->SetVisibility(ESlateVisibility::Hidden);
	Step23To24->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step23To24Clicked()
{
	Step24Txt->SetVisibility(ESlateVisibility::Visible);
	Step24To23->SetVisibility(ESlateVisibility::Visible);
	Step24To25->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Hidden);
	Step23To22->SetVisibility(ESlateVisibility::Hidden);
	Step23To24->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step24To23Clicked()
{
	Step23Txt->SetVisibility(ESlateVisibility::Visible);
	Step23To22->SetVisibility(ESlateVisibility::Visible);
	Step23To24->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Hidden);
	Step24To23->SetVisibility(ESlateVisibility::Hidden);
	Step24To25->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step24To25Clicked()
{
	Step25Txt->SetVisibility(ESlateVisibility::Visible);
	Step25To24->SetVisibility(ESlateVisibility::Visible);
	Step25To26->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Hidden);
	Step24To23->SetVisibility(ESlateVisibility::Hidden);
	Step24To25->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step25To24Clicked()
{
	Step24Txt->SetVisibility(ESlateVisibility::Visible);
	Step24To23->SetVisibility(ESlateVisibility::Visible);
	Step24To25->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Hidden);
	Step25To24->SetVisibility(ESlateVisibility::Hidden);
	Step25To26->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step25To26Clicked()
{
	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Hidden);
	Step25To24->SetVisibility(ESlateVisibility::Hidden);
	Step25To26->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step26To25Clicked()
{
	Step25Txt->SetVisibility(ESlateVisibility::Visible);
	Step25To24->SetVisibility(ESlateVisibility::Visible);
	Step25To26->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step26To27Clicked()
{
	Step27Txt->SetVisibility(ESlateVisibility::Visible);
	Step27To26->SetVisibility(ESlateVisibility::Visible);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::Step27To26Clicked()
{
	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

}

void UQueensGambitUserWidget::Step27ToSelectVariationClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
}

