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
	StepEightToNine_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepEightToNine_1Clicked);
	StepEightToNine_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepEightToNine_2Clicked);
	
	StepNineToEight->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToEightClicked);
	StepNineToEight_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToEight_1Clicked);
	StepNineToEight_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToEight_2Clicked);
	StepNineToTen->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToTenClicked);
	StepNineToTen_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNineToTen_1Clicked);
	
	StepTenToNine->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenToNineClicked);	
	StepTenToNine_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenToNine_1Clicked);	
	StepTenTo11->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenTo11Clicked);
	StepTenTo11_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenTo11_1Clicked);
	StepTenTo11_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenTo11_2Clicked);
	StepTenTo11_3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepTenTo11_3Clicked);
	
	Step11ToTen->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToTenClicked);	
	Step11ToTen_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToTen_1Clicked);	
	Step11ToTen_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToTen_2Clicked);	
	Step11ToTen_3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToTen_3Clicked);	
	Step11ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step11ToSelectVariationClicked);
	
	Step12ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step12ToSelectVariationClicked);
	Step12To13->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step12To13Clicked);
	
	Step13To12->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step13To12Clicked);
	Step13To14->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step13To14Clicked);
	
	Step14To13->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To13Clicked);
	Step14To15->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15Clicked);
	Step14To15_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15_1Clicked);
	Step14To15_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15_2Clicked);
	Step14To15_3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15_3Clicked);
	Step14To15_4->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step14To15_4Clicked);
	
	Step15To14->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14Clicked);
	Step15To14_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14_1Clicked);
	Step15To14_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14_2Clicked);
	Step15To14_3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14_3Clicked);
	Step15To14_4->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To14_4Clicked);
	Step15To16->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To16Clicked);
	Step15To16_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To16_1Clicked);
	Step15To16_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step15To16_2Clicked);

	Step16To15->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To15Clicked);
	Step16To15_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To15_1Clicked);
	Step16To15_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To15_2Clicked);
	Step16To17->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To17Clicked);
	Step16To17_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To17_1Clicked);
	Step16To17_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step16To17_2Clicked);
	
	Step17To16->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To16Clicked);
	Step17To16_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To16_1Clicked);
	Step17To16_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To16_2Clicked);
	Step17To18->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step17To18Clicked);
	
	Step18To17->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step18To17Clicked);
	Step18ToSelectVariation_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step18ToSelectVariation_1Clicked);
	
	Step20ToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step20ToSelectVariationClicked);
	Step20To21->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step20To21Clicked);
	Step20To21_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step20To21_1Clicked);
	
	Step21To20->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step21To20Clicked);
	Step21To20_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step21To20_1Clicked);
	Step21To22->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step21To22Clicked);

	Step22To21->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step22To21Clicked);
	Step22To23->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step22To23Clicked);

	Step23To22->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step23To22Clicked);
	Step23To24->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step23To24Clicked);

	Step24To23->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step24To23Clicked);
	Step24To25->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step24To25Clicked);

	Step25To24->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step25To24Clicked);
	Step25To26->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step25To26Clicked);
	Step25To26_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step25To26_1Clicked);

	Step26To25->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To25Clicked);
	Step26To25_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To25_1Clicked);
	Step26To27->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27Clicked);
	Step26To27_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27_1Clicked);
	Step26To27_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27_2Clicked);

	Step27To26->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27Clicked);
	Step27To26_1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27_1Clicked);
	Step27To26_2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::Step26To27_2Clicked);
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
	//FTimerHandle TH_InputDelay;
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
	//GetWorld()->GetTimerManager().SetTimer(TH_InputDelay, this, &URuyLopezUserWidget::StepZeroToOneClicked, 1, false);
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

	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepFourTxt->SetVisibility(ESlateVisibility::Visible);
	StepFourToFive->SetVisibility(ESlateVisibility::Visible);

}

void URuyLopezUserWidget::StepFourToSelectVariationClicked()
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

	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	StepFourTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFourToFive->SetVisibility(ESlateVisibility::Hidden);

}

void URuyLopezUserWidget::StepFourToFiveClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	StepFourTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFourToFive->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Visible);
	StepFiveToFour->SetVisibility(ESlateVisibility::Visible);
	StepFiveToSix->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->BlackPawns[0], FVector(2000.f, 0.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(2000.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::StepFiveToFourClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToFour->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToSix->SetVisibility(ESlateVisibility::Hidden);

	StepFourToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepFourTxt->SetVisibility(ESlateVisibility::Visible);
	StepFourToFive->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->BlackPawns[0], TrainerController->BlackPawns[0]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepFiveToSixClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToFour->SetVisibility(ESlateVisibility::Hidden);
	StepFiveToSix->SetVisibility(ESlateVisibility::Hidden);

	StepSixTxt->SetVisibility(ESlateVisibility::Visible);
	StepSixToFive->SetVisibility(ESlateVisibility::Visible);
	StepSixToSeven->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 800.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(2000.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::StepSixToFiveClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepFiveTxt->SetVisibility(ESlateVisibility::Visible);
	StepFiveToFour->SetVisibility(ESlateVisibility::Visible);
	StepFiveToSix->SetVisibility(ESlateVisibility::Visible);

	StepSixTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSixToFive->SetVisibility(ESlateVisibility::Hidden);
	StepSixToSeven->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepSixToSevenClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepSevenTxt->SetVisibility(ESlateVisibility::Visible);
	StepSevenToSix->SetVisibility(ESlateVisibility::Visible);
	StepSevenToEight->SetVisibility(ESlateVisibility::Visible);

	StepSixTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSixToFive->SetVisibility(ESlateVisibility::Hidden);
	StepSixToSeven->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::StepSevenToSixClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepSixTxt->SetVisibility(ESlateVisibility::Visible);
	StepSixToFive->SetVisibility(ESlateVisibility::Visible);
	StepSixToSeven->SetVisibility(ESlateVisibility::Visible);
	
	StepSevenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToSix->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToEight->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepSevenToEightClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepSevenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToSix->SetVisibility(ESlateVisibility::Hidden);
	StepSevenToEight->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], FVector(1200.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::StepEightToSevenClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepSevenTxt->SetVisibility(ESlateVisibility::Visible);
	StepSevenToSix->SetVisibility(ESlateVisibility::Visible);
	StepSevenToEight->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[4], TrainerController->BlackPawns[4]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepEightToNineClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, FVector(0.f, 2400.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteRooks[1], FVector(0.f, 2000.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[5], FVector(2000.f, 2000.f, 0.5f));

}

void URuyLopezUserWidget::StepNineToEightClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, TrainerController->WhiteKing->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteRooks[1], TrainerController->WhiteRooks[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[5], TrainerController->BlackPawns[5]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepEightToNine_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[1], FVector(1600.f, 800.f, 0.5f));
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(800.f, 1200.f, 0.5f));

}

void URuyLopezUserWidget::StepNineToEight_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepEightToNine_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepEightTxt->SetVisibility(ESlateVisibility::Hidden);
	StepEightToSeven->SetVisibility(ESlateVisibility::Hidden);
	StepEightToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[0], FVector(1200.f, 0.f, 0.5f));

}

void URuyLopezUserWidget::StepNineToEight_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepEightTxt->SetVisibility(ESlateVisibility::Visible);
	StepEightToSeven->SetVisibility(ESlateVisibility::Visible);
	StepEightToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[0], TrainerController->WhitePawns[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepNineToTenClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], FVector(800.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::StepTenToNineClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepNineToTen_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	StepNineTxt->SetVisibility(ESlateVisibility::Hidden);
	StepNineToEight->SetVisibility(ESlateVisibility::Hidden);
	StepNineToTen->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], FVector(800.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::StepTenToNine_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepNineTxt->SetVisibility(ESlateVisibility::Visible);
	StepNineToEight->SetVisibility(ESlateVisibility::Visible);
	StepNineToTen->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], FVector(800.f, 2000.f, 0.5f));
}

void URuyLopezUserWidget::StepTenTo11Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step11Txt->SetVisibility(ESlateVisibility::Visible);
	Step11ToTen->SetVisibility(ESlateVisibility::Visible);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[5], FVector(2000.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::Step11ToTenClicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);
	
	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[5], TrainerController->BlackPawns[5]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepTenTo11_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step11Txt->SetVisibility(ESlateVisibility::Visible);
	Step11ToTen->SetVisibility(ESlateVisibility::Visible);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1600.f, 2000.f, 0.5f));
}

void URuyLopezUserWidget::Step11ToTen_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
}
 
void URuyLopezUserWidget::StepTenTo11_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step11Txt->SetVisibility(ESlateVisibility::Visible);
	Step11ToTen->SetVisibility(ESlateVisibility::Visible);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, FVector(0.f, 2400.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteRooks[1], FVector(0.f, 2000.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(2000.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::Step11ToTen_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, TrainerController->WhiteKing->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteRooks[1], TrainerController->WhiteRooks[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::StepTenTo11_3Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step11Txt->SetVisibility(ESlateVisibility::Visible);
	Step11ToTen->SetVisibility(ESlateVisibility::Visible);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepTenTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTenTo11->SetVisibility(ESlateVisibility::Hidden);
	StepTenToNine->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[0], FVector(1600.f, 2000.f, 0.5f));
}

void URuyLopezUserWidget::Step11ToTen_3Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Visible);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTenTxt->SetVisibility(ESlateVisibility::Visible);
	StepTenTo11->SetVisibility(ESlateVisibility::Visible);
	StepTenToNine->SetVisibility(ESlateVisibility::Visible);

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[0], TrainerController->BlackBishops[0]->OriginalSpawnLocation);

}

void URuyLopezUserWidget::Step11ToSelectVariationClicked()
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

	Step11Txt->SetVisibility(ESlateVisibility::Hidden);
	Step11ToTen->SetVisibility(ESlateVisibility::Hidden);
	Step11ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
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

	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step12To13->SetVisibility(ESlateVisibility::Visible);
	Step12Txt->SetVisibility(ESlateVisibility::Visible);

}

void URuyLopezUserWidget::Step12ToSelectVariationClicked()
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

	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);

}

void URuyLopezUserWidget::Step12To13Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step12Txt->SetVisibility(ESlateVisibility::Hidden);
	Step12To13->SetVisibility(ESlateVisibility::Hidden);

	Step13Txt->SetVisibility(ESlateVisibility::Visible);
	Step13To12->SetVisibility(ESlateVisibility::Visible);
	Step13To14->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->BlackPawns[0], FVector(2000.f, 0.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1200.f, 0.f, 0.5f));
}

void URuyLopezUserWidget::Step13To12Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step12Txt->SetVisibility(ESlateVisibility::Visible);
	Step12ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step12To13->SetVisibility(ESlateVisibility::Visible);

	Step13Txt->SetVisibility(ESlateVisibility::Hidden);
	Step13To12->SetVisibility(ESlateVisibility::Hidden);
	Step13To14->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[0], TrainerController->BlackPawns[0]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step13To14Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step13Txt->SetVisibility(ESlateVisibility::Hidden);
	Step13To12->SetVisibility(ESlateVisibility::Hidden);
	Step13To14->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->WhiteKing, FVector(0.f, 2400.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteRooks[1], FVector(0.f, 2000.f, 0.5f));
	TrainerController->Move(TrainerController->BlackKnights[1], FVector(2000.f, 2000.f, 0.5f));
}

void URuyLopezUserWidget::Step14To13Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step13Txt->SetVisibility(ESlateVisibility::Visible);
	Step13To12->SetVisibility(ESlateVisibility::Visible);
	Step13To14->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, TrainerController->WhiteKing->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteRooks[1], TrainerController->WhiteRooks[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackKnights[1], TrainerController->BlackKnights[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step14To15Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::Step15To14Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);
}


void URuyLopezUserWidget::Step14To15_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(800.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(1600.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::Step15To14_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step14To15_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(2000.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::Step15To14_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(1600.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::Step14To15_3Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], FVector(400.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));
	
}

void URuyLopezUserWidget::Step15To14_3Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step14To15_4Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step14Txt->SetVisibility(ESlateVisibility::Hidden);
	Step14To13->SetVisibility(ESlateVisibility::Hidden);
	Step14To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[0], FVector(1200.f, 0.f, 0.5f));
}

void URuyLopezUserWidget::Step15To14_4Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step14Txt->SetVisibility(ESlateVisibility::Visible);
	Step14To13->SetVisibility(ESlateVisibility::Visible);
	Step14To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[0], TrainerController->WhitePawns[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step15To16Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::Step16To15Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::Step15To16_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(800.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(1600.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::Step16To15_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step15To16_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step15Txt->SetVisibility(ESlateVisibility::Hidden);
	Step15To14->SetVisibility(ESlateVisibility::Hidden);
	Step15To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], FVector(400.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::Step16To15_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step15Txt->SetVisibility(ESlateVisibility::Visible);
	Step15To14->SetVisibility(ESlateVisibility::Visible);
	Step15To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step16To17Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(800.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::Step17To16Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step16To17_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], FVector(400.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::Step17To16_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step16To17_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step16Txt->SetVisibility(ESlateVisibility::Hidden);
	Step16To17->SetVisibility(ESlateVisibility::Hidden);
	Step16To15->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[0], FVector(1200.f, 2400.f, 0.5f));
}

void URuyLopezUserWidget::Step17To16_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step16Txt->SetVisibility(ESlateVisibility::Visible);
	Step16To17->SetVisibility(ESlateVisibility::Visible);
	Step16To15->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackBishops[0], TrainerController->BlackBishops[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step17To18Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step18Txt->SetVisibility(ESlateVisibility::Visible);
	Step18ToSelectVariation_1->SetVisibility(ESlateVisibility::Visible);
	Step18To17->SetVisibility(ESlateVisibility::Visible);

	Step17Txt->SetVisibility(ESlateVisibility::Hidden);
	Step17To18->SetVisibility(ESlateVisibility::Hidden);
	Step17To16->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackRooks[0], FVector(2800.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[1], FVector(1200.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::Step18To17Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Visible);
	TheClosedDefense->SetVisibility(ESlateVisibility::Hidden);

	Step17Txt->SetVisibility(ESlateVisibility::Visible);
	Step17To18->SetVisibility(ESlateVisibility::Visible);
	Step17To16->SetVisibility(ESlateVisibility::Visible);

	Step18Txt->SetVisibility(ESlateVisibility::Hidden);
	Step18ToSelectVariation_1->SetVisibility(ESlateVisibility::Hidden);
	Step18To17->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackRooks[0], TrainerController->BlackRooks[0]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[0], TrainerController->BlackPawns[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step18ToSelectVariation_1Clicked()
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

	Step18Txt->SetVisibility(ESlateVisibility::Hidden);
	Step18ToSelectVariation_1->SetVisibility(ESlateVisibility::Hidden);
	Step18To17->SetVisibility(ESlateVisibility::Hidden);

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

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step20To21->SetVisibility(ESlateVisibility::Visible);
	Step20Txt->SetVisibility(ESlateVisibility::Visible);
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

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step20To21->SetVisibility(ESlateVisibility::Hidden);
	Step20Txt->SetVisibility(ESlateVisibility::Hidden);
}

void URuyLopezUserWidget::Step20To21Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step20Txt->SetVisibility(ESlateVisibility::Hidden);
	Step20To21->SetVisibility(ESlateVisibility::Hidden);

	Step21Txt->SetVisibility(ESlateVisibility::Visible);
	Step21To20->SetVisibility(ESlateVisibility::Visible);
	Step21To22->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1200.f, 0.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteKnights[1], FVector(2000.f, 2000.f, 0.5f));
}

void URuyLopezUserWidget::Step21To20Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step20Txt->SetVisibility(ESlateVisibility::Visible);
	Step20To21->SetVisibility(ESlateVisibility::Visible);

	Step21Txt->SetVisibility(ESlateVisibility::Hidden);
	Step21To20->SetVisibility(ESlateVisibility::Hidden);
	Step21To22->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackKnights[1], TrainerController->BlackKnights[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step20To21_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Step20Txt->SetVisibility(ESlateVisibility::Hidden);
	Step20To21->SetVisibility(ESlateVisibility::Hidden);

	Step21Txt->SetVisibility(ESlateVisibility::Visible);
	Step21To20->SetVisibility(ESlateVisibility::Visible);
	Step21To22->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->WhiteKing, FVector(0.f, 2400.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteRooks[1], FVector(0.f, 2000.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(1600.f, 2400.f, 0.5f));
}

void URuyLopezUserWidget::Step21To20_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step20ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	Step20Txt->SetVisibility(ESlateVisibility::Visible);
	Step20To21->SetVisibility(ESlateVisibility::Visible);

	Step21Txt->SetVisibility(ESlateVisibility::Hidden);
	Step21To20->SetVisibility(ESlateVisibility::Hidden);
	Step21To22->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteKing, TrainerController->WhiteKing->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteRooks[1], TrainerController->WhiteRooks[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step21To22Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step22Txt->SetVisibility(ESlateVisibility::Visible);
	Step22To21->SetVisibility(ESlateVisibility::Visible);
	Step22To23->SetVisibility(ESlateVisibility::Visible);

	Step21Txt->SetVisibility(ESlateVisibility::Hidden);
	Step21To20->SetVisibility(ESlateVisibility::Hidden);
	Step21To22->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteRooks[1], FVector(0.f, 1600.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteKnights[1], FVector(2400.f, 800.f, 0.5f));
}

void URuyLopezUserWidget::Step22To21Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step22Txt->SetVisibility(ESlateVisibility::Hidden);
	Step22To21->SetVisibility(ESlateVisibility::Hidden);
	Step22To23->SetVisibility(ESlateVisibility::Hidden);

	Step21Txt->SetVisibility(ESlateVisibility::Visible);
	Step21To20->SetVisibility(ESlateVisibility::Visible);
	Step21To22->SetVisibility(ESlateVisibility::Visible);

	TrainerController->Move(TrainerController->WhiteRooks[1], TrainerController->WhiteRooks[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteKnights[1], TrainerController->WhiteKnights[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step22To23Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Visible);
	Step23To22->SetVisibility(ESlateVisibility::Visible);
	Step23To24->SetVisibility(ESlateVisibility::Visible);

	Step22Txt->SetVisibility(ESlateVisibility::Hidden);
	Step22To21->SetVisibility(ESlateVisibility::Hidden);
	Step22To23->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
}

void URuyLopezUserWidget::Step23To22Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step22Txt->SetVisibility(ESlateVisibility::Visible);
	Step22To21->SetVisibility(ESlateVisibility::Visible);
	Step22To23->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Hidden);
	Step23To22->SetVisibility(ESlateVisibility::Hidden);
	Step23To24->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step23To24Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Visible);
	Step24To23->SetVisibility(ESlateVisibility::Visible);
	Step24To25->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Hidden);
	Step23To22->SetVisibility(ESlateVisibility::Hidden);
	Step23To24->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(800.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::Step24To23Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step23Txt->SetVisibility(ESlateVisibility::Visible);
	Step23To22->SetVisibility(ESlateVisibility::Visible);
	Step23To24->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Hidden);
	Step24To23->SetVisibility(ESlateVisibility::Hidden);
	Step24To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step24To25Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Visible);
	Step25To24->SetVisibility(ESlateVisibility::Visible);
	Step25To26->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Hidden);
	Step24To23->SetVisibility(ESlateVisibility::Hidden);
	Step24To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], FVector(1200.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::Step25To24Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step24Txt->SetVisibility(ESlateVisibility::Visible);
	Step24To23->SetVisibility(ESlateVisibility::Visible);
	Step24To25->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Hidden);
	Step25To24->SetVisibility(ESlateVisibility::Hidden);
	Step25To26->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step25To26Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Hidden);
	Step25To24->SetVisibility(ESlateVisibility::Hidden);
	Step25To26->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[7], FVector(2800.f, 800.f, 0.5f));
	TrainerController->Move(TrainerController->BlackPawns[1], FVector(400.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::Step26To25Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Visible);
	Step25To24->SetVisibility(ESlateVisibility::Visible);
	Step25To26->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[7], TrainerController->WhitePawns[7]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackPawns[1], TrainerController->BlackPawns[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step25To26_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Hidden);
	Step25To24->SetVisibility(ESlateVisibility::Hidden);
	Step25To26->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(400.f, 800.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(400.f, 2400.f, 0.5f));
}

void URuyLopezUserWidget::Step26To25_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step25Txt->SetVisibility(ESlateVisibility::Visible);
	Step25To24->SetVisibility(ESlateVisibility::Visible);
	Step25To26->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step26To27Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Visible);
	Step27To26->SetVisibility(ESlateVisibility::Visible);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], FVector(400.f, 400.f, 0.5f));
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(400.f, 1600.f, 0.5f));
}

void URuyLopezUserWidget::Step27To26Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step26To27_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Visible);
	Step27To26->SetVisibility(ESlateVisibility::Visible);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[1], FVector(1600.f, 0.f, 0.5f));
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(800.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::Step27To26_1Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackPawns[1], TrainerController->BlackPawns[1]->OriginalSpawnLocation);
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1200.f, 0.f, 0.5f));
}

void URuyLopezUserWidget::Step26To27_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Visible);
	Step27To26->SetVisibility(ESlateVisibility::Visible);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Hidden);
	Step26To27->SetVisibility(ESlateVisibility::Hidden);
	Step26To25->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackRooks[0], FVector(2800.f, 400.f, 0.5f));
}

void URuyLopezUserWidget::Step27To26_2Clicked()
{
	RuyLopezBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	TheExchangeVariation->SetVisibility(ESlateVisibility::Hidden);
	ArkhangelskDefense->SetVisibility(ESlateVisibility::Hidden);
	TheClosedDefense->SetVisibility(ESlateVisibility::Visible);

	Step26Txt->SetVisibility(ESlateVisibility::Visible);
	Step26To25->SetVisibility(ESlateVisibility::Visible);
	Step26To27->SetVisibility(ESlateVisibility::Visible);

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	TrainerController->Move(TrainerController->BlackRooks[0], TrainerController->BlackRooks[0]->OriginalSpawnLocation);
}

void URuyLopezUserWidget::Step27ToSelectVariationClicked()
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

	Step27Txt->SetVisibility(ESlateVisibility::Hidden);
	Step27To26->SetVisibility(ESlateVisibility::Hidden);
	Step27ToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}
