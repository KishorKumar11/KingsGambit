 //King's Gambit by Jonathan Mui and Kishor Kumar


#include "RuyLopezUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
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

	StepEVToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepEVToSelectVariationClicked);
	StepADToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADToSelectVariationClicked);
	StepCDToSelectVariation->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDToSelectVariationClicked);

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

	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
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

	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
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

	TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));
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

	TrainerController->Move(TrainerController->WhiteKnights[1], TrainerController->WhiteKnights[1]->OriginalSpawnLocation);
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

	//TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1600.f, 400.f, 0.5f));
}

/////////////////////////// THE EXCHANGE VARIATION ////////////////////////////////////

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

	EVTxt->SetVisibility(ESlateVisibility::Visible);
	EV1Txt->SetVisibility(ESlateVisibility::Visible);
	EV2Txt->SetVisibility(ESlateVisibility::Visible);
	EV_Main->SetVisibility(ESlateVisibility::Visible);
	EV_WP->SetVisibility(ESlateVisibility::Visible);
	EV_BP->SetVisibility(ESlateVisibility::Visible);
	StepEVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
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

	EV_WP->SetVisibility(ESlateVisibility::Hidden);
	EV_BP->SetVisibility(ESlateVisibility::Hidden);
	StepEVToSelectVariation->SetVisibility(ESlateVisibility::Hidden);

	EVTxt->SetVisibility(ESlateVisibility::Hidden);
	EV1Txt->SetVisibility(ESlateVisibility::Hidden);
	EV2Txt->SetVisibility(ESlateVisibility::Hidden);
	EV_Main->SetVisibility(ESlateVisibility::Hidden);
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

	ADTxt->SetVisibility(ESlateVisibility::Visible);
	AD1Txt->SetVisibility(ESlateVisibility::Visible);
	AD2Txt->SetVisibility(ESlateVisibility::Visible);
	AD_Main->SetVisibility(ESlateVisibility::Visible);
	AD_WP->SetVisibility(ESlateVisibility::Visible);
	AD_BP->SetVisibility(ESlateVisibility::Visible);
	StepADToSelectVariation->SetVisibility(ESlateVisibility::Visible);
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

	StepADToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
	AD_WP->SetVisibility(ESlateVisibility::Hidden);
	AD_BP->SetVisibility(ESlateVisibility::Hidden);
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

	CDTxt->SetVisibility(ESlateVisibility::Visible);
	CD1Txt->SetVisibility(ESlateVisibility::Visible);
	CD_Main->SetVisibility(ESlateVisibility::Visible);
	CD_WP->SetVisibility(ESlateVisibility::Visible);
	CD_BP->SetVisibility(ESlateVisibility::Visible);
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

	CD_WP->SetVisibility(ESlateVisibility::Hidden);
	CD_BP->SetVisibility(ESlateVisibility::Hidden);
	StepCDToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}
