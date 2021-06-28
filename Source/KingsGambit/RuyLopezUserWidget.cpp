 //King's Gambit by Jonathan Mui and Kishor Kumar


#include "RuyLopezUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void URuyLopezUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::QuitButtonClicked);
	
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepZeroToOneClicked);
	
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepOneToTwoClicked);
	
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTwoToThreeClicked);
	
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepThreeToTwoClicked);	
	StepThreeToSelect_Variation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepThreeToSelect_VariationClicked);
	
	StepFourToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepFourToSelectVariationClicked);
	StepFourToFive->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepFourToFiveClicked);
	
	StepFiveToFour->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepFiveToFourClicked);
	StepFiveToSix->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepFiveToSixClicked);
	
	StepSixToFive->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepSixToFiveClicked);
	StepSixToSeven->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepSixToSevenClicked);
	
	StepSevenToSix->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepSevenToSixClicked);
	StepSevenToEight->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepSevenToEightClicked);
	
	StepEightToSeven->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepEightToSevenClicked);
	StepEightToNine->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepEightToNineClicked);
	
	StepNineToEight->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToEightClicked);
	StepNineToTen->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToTenClicked);
	
	StepTenToNine->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenToNineClicked);	
	StepTenTo11->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenTo11Clicked);
	
	Step11ToTen->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToTenClicked);	
	Step11ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToSelectVariationClicked);
	
	Step12ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step12ToSelectVariationClicked);
	Step12To13->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step12To13Clicked);
	
	Step13To12->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step13To12Clicked);
	Step13To14->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step13To14Clicked);
	
	Step14To13->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To13Clicked);
	Step14To15->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15Clicked);
	
	Step15To14->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14Clicked);
	Step15To16->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To16Clicked);

	Step16To15->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To15Clicked);
	Step16To17->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To17Clicked);
	
	Step17To16->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To16Clicked);
	Step17To18->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To18Clicked);
	
	Step18To17->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step18To17Clicked);
	Step18ToSelectVariation_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step18ToSelectVariation_1Clicked);
	
	Step20ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step20ToSelectVariationClicked);
	Step20To21->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step20To21Clicked);
	
	Step21To20->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step21To20Clicked);
	Step21To22->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step21To22Clicked);

	Step22To21->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step22To21Clicked);
	Step22To23->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step22To23Clicked);

	Step23To22->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step23To22Clicked);
	Step23To24->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step23To24Clicked);

	Step24To23->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step24To23Clicked);
	Step24To25->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step24To25Clicked);

	Step25To24->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step25To24Clicked);
	Step25To26->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step25To26Clicked);

	Step26To25->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To25Clicked);
	Step26To27->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27Clicked);

	Step27To26->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27Clicked);
	Step27ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step27ToSelectVariationClicked);

	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepSelectVariationToThreeClicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::MainMenuButtonClicked);

	StepExchangeVariationtoStepFour->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepExchangeVariationtoStepFourClicked);
	StepArkhangelskDefensetoStep12->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepArkhangelskDefensetoStep12Clicked);
	StepTheClosedDefenseto20->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTheClosedDefenseto20Clicked);
}

void URuyLopezUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void URuyLopezUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void URuyLopezUserWidget::StepZeroToOneClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);
	
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[4], FVector(1600.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::StepOneToZeroClicked()
{

	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[4], TrainerController->BlackPawns[4]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepOneToTwoClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King's Knight moves forward [kf3] 
	TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));

	//Black's Queen's Knight moves forward [kc6]
	TrainerController->Move(TrainerController->BlackKnights[0], FVector(2000.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::StepTwoToOneClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Knight back to its original position
	TrainerController->Move(TrainerController->WhiteKnights[1], TrainerController->WhiteKnights[1]->OriginalSpawnLocation);
	//Black's Knight back to its original position
	TrainerController->Move(TrainerController->BlackKnights[0], TrainerController->BlackKnights[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepTwoToThreeClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King's Bishop moves forward to pin the opponents Knight 
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1600.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::StepThreeToTwoClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Bishop back to its original position
	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepThreeToSelect_VariationClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);
	
	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Visible);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	
	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::StepSelectVariationToThreeClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King's Bishop moves forward to pin the opponents Knight 
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1600.f, 400.f, 0.5f));
}

///////////////////////////// THE EXCHANGE VARIATION ////////////////////////////////////

void URuyLopezUserWidget::StepExchangeVariationtoStepFourClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Hidden);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Hidden);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Hidden);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Hidden);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Hidden);

	EVTxt->SetVisibility(ESlateVisibility::Visible);
	EV1Txt->SetVisibility(ESlateVisibility::Visible);
	EV2Txt->SetVisibility(ESlateVisibility::Visible);
	EV_Main->SetVisibility(ESlateVisibility::Visible);
	/*EV_WP->SetVisibility(ESlateVisibility::Visible);
	EV_BP->SetVisibility(ESlateVisibility::Visible);*/
}

void URuyLopezUserWidget::StepEVNextClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepEVWP1->SetVisibility(ESlateVisibility::Visible);
	StepEVWP2->SetVisibility(ESlateVisibility::Visible);
	StepEVWP3->SetVisibility(ESlateVisibility::Visible);
	StepEVBP1->SetVisibility(ESlateVisibility::Visible);
	StepEVBP2->SetVisibility(ESlateVisibility::Visible);
	StepEVBP3->SetVisibility(ESlateVisibility::Visible);
	StepEVBP4->SetVisibility(ESlateVisibility::Visible);
	StepEV_WP->SetVisibility(ESlateVisibility::Visible);
	StepEV_BP->SetVisibility(ESlateVisibility::Visible);
	StepEVToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	EVTxt->SetVisibility(ESlateVisibility::Hidden);
	EV1Txt->SetVisibility(ESlateVisibility::Hidden);
	EV2Txt->SetVisibility(ESlateVisibility::Hidden);
	EV_Main->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::StepEVToSelectVariationClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Visible);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Visible);

	StepEVWP1->SetVisibility(ESlateVisibility::Hidden);
	StepEVWP2->SetVisibility(ESlateVisibility::Hidden);
	StepEVWP3->SetVisibility(ESlateVisibility::Hidden);
	StepEVBP1->SetVisibility(ESlateVisibility::Hidden);
	StepEVBP2->SetVisibility(ESlateVisibility::Hidden);
	StepEVBP3->SetVisibility(ESlateVisibility::Hidden);
	StepEVBP4->SetVisibility(ESlateVisibility::Hidden);
	StepEV_WP->SetVisibility(ESlateVisibility::Hidden);
	StepEV_BP->SetVisibility(ESlateVisibility::Hidden);
	StepEVToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

///////////////////////////// ARKHANGELSK DEFENSE VARIATION ////////////////////////////////////

void URuyLopezUserWidget::StepArkhangelskDefensetoStep12Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Hidden);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Hidden);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Hidden);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Hidden);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Hidden);

	StepADTxt->SetVisibility(ESlateVisibility::Visible);
	StepAD1Txt->SetVisibility(ESlateVisibility::Visible);
	StepAD2Txt->SetVisibility(ESlateVisibility::Visible);
	StepAD_Main->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::StepADNextClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step12Txt->SetVisibility(ESlateVisibility::Hidden);
	Step12To13->SetVisibility(ESlateVisibility::Hidden);

	StepADBP1->SetVisibility(ESlateVisibility::Visible);
	StepADBP2->SetVisibility(ESlateVisibility::Visible);
	StepADBP3->SetVisibility(ESlateVisibility::Visible);
	StepADWP1->SetVisibility(ESlateVisibility::Visible);
	StepADWP2->SetVisibility(ESlateVisibility::Visible);
	StepADWP3->SetVisibility(ESlateVisibility::Visible);
	StepADToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepAD_WP->SetVisibility(ESlateVisibility::Visible);
	StepAD_BP->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::StepADToSelectVariationClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Visible);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Visible);

	StepADBP1->SetVisibility(ESlateVisibility::Hidden);
	StepADBP2->SetVisibility(ESlateVisibility::Hidden);
	StepADBP3->SetVisibility(ESlateVisibility::Hidden);
	StepADWP1->SetVisibility(ESlateVisibility::Hidden);
	StepADWP2->SetVisibility(ESlateVisibility::Hidden);
	StepADWP3->SetVisibility(ESlateVisibility::Hidden);
	StepADToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	StepAD_WP->SetVisibility(ESlateVisibility::Hidden);
	StepAD_BP->SetVisibility(ESlateVisibility::Hidden);
}

///////////////////////////// THE CLOSED DEFENSE VARIATION ////////////////////////////////////

void URuyLopezUserWidget::StepTheClosedDefenseto20Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Hidden);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Hidden);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Hidden);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Hidden);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Hidden);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Hidden);

	StepCDTxt->SetVisibility(ESlateVisibility::Visible);
	StepCD1Txt->SetVisibility(ESlateVisibility::Visible);
	StepCDNext->SetVisibility(ESlateVisibility::Visible);
	StepCD_Main->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::Step20ToSelectVariationClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Visible);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Visible);
	
	StepCDBP1->SetVisibility(ESlateVisibility::Visible);
	StepCDBP2->SetVisibility(ESlateVisibility::Visible);
	StepCDBP3->SetVisibility(ESlateVisibility::Visible);
	StepCDWP1->SetVisibility(ESlateVisibility::Visible);
	StepCDWP2->SetVisibility(ESlateVisibility::Visible);
	StepCD_WP->SetVisibility(ESlateVisibility::Visible);
	StepCD_BP->SetVisibility(ESlateVisibility::Visible);
	StepCDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
}

void URuyLopezUserWidget::StepCDToSelectVariationClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepExchangeVariationtoStepFour->SetVisibility(ESlateVisibility::Visible);
	StepArkhangelskDefensetoStep12->SetVisibility(ESlateVisibility::Visible);
	StepTheClosedDefenseto20->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);

	TheExchangeVariationTxt->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefenseTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);
	SelectVariationToThreetxt->SetVisibility(ESlateVisibility::Visible);

	StepCDBP1->SetVisibility(ESlateVisibility::Hidden);
	StepCDBP2->SetVisibility(ESlateVisibility::Hidden);
	StepCDBP3->SetVisibility(ESlateVisibility::Hidden);
	StepCDWP1->SetVisibility(ESlateVisibility::Hidden);
	StepCDWP2->SetVisibility(ESlateVisibility::Hidden);
	StepCD_WP->SetVisibility(ESlateVisibility::Hidden);
	StepCD_BP->SetVisibility(ESlateVisibility::Hidden);
	StepCDToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}
