// King's Gambit by Jonathan Mui and Kishor Kumar


#include "KingsIndianDefenceUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UKingsIndianDefenceUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepThreeToTwoClicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::MainMenuButtonClicked);
	StepThreeToSelect_Variation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepThreeToSelect_VariationClicked);

	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSelectVariationToThreeClicked);
	StepPetrosianVariation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPetrosianVariationClicked);
	StepSamischVariation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSamischVariationClicked);
	StepFourPawnsAttack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFourPawnsAttackClicked);

	StepPVWP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVWP1Clicked);
	StepPVWP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVWP1ToBackClicked);
	StepPVWP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVWP2Clicked);
	StepPVWP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVWP2ToBackClicked);
	StepPVBP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVBP1Clicked);
	StepPVBP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVBP1ToBackClicked);
	StepPVBP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVBP2Clicked);
	StepPVBP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVBP2ToBackClicked);
	StepPVToSelectVariation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepPVToSelectVariationClicked);

	StepSVWP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVWP1Clicked);
	StepSVWP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVWP1ToBackClicked);
	StepSVWP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVWP2Clicked);
	StepSVWP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVWP2ToBackClicked);
	StepSVBP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVBP1Clicked);
	StepSVBP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVBP1ToBackClicked);
	StepSVBP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVBP2Clicked);
	StepSVBP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVBP2ToBackClicked);
	StepSVToSelectVariation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepSVToSelectVariationClicked);

	StepFPAWP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPAWP1Clicked);
	StepFPAWP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPAWP1ToBackClicked);
	StepFPAWP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPAWP2Clicked);
	StepFPAWP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPAWP2ToBackClicked);
	StepFPABP1->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPABP1Clicked);
	StepFPABP1ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPABP1ToBackClicked);
	StepFPABP2->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPABP2Clicked);
	StepFPABP2ToBack->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPABP2ToBackClicked);
	StepFPAToSelectVariation->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepFPAToSelectVariationClicked);
}

void UKingsIndianDefenceUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UKingsIndianDefenceUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UKingsIndianDefenceUserWidget::StepZeroToOneClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
	//Black's King side Knight 
	TrainerController->Move(TrainerController->BlackKnights[1], FVector(2000.f, 2000.f, 0.5f));
}

void UKingsIndianDefenceUserWidget::StepOneToZeroClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
	//Black's Knight back to its original position
	TrainerController->Move(TrainerController->BlackKnights[1], TrainerController->BlackKnights[1]->OriginalSpawnLocation);
}

void UKingsIndianDefenceUserWidget::StepOneToTwoClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[2], FVector(1200.f, 800.f, 0.5f));
	//Black's Pawn Moves 1 step forward
	TrainerController->Move(TrainerController->BlackPawns[6], FVector(2000.f, 2400.f, 0.5f));

}

void UKingsIndianDefenceUserWidget::StepTwoToOneClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[6], TrainerController->BlackPawns[6]->OriginalSpawnLocation);

}

void UKingsIndianDefenceUserWidget::StepTwoToThreeClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Queen side Knight 
	TrainerController->Move(TrainerController->WhiteKnights[0], FVector(800.f, 800.f, 0.5f));
	//Black's King side Bishop Moves 1 step forward
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(2400.f, 2400.f, 0.5f));
	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));

}

void UKingsIndianDefenceUserWidget::StepThreeToTwoClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);

	//White's Knight back to its original position
	TrainerController->Move(TrainerController->WhiteKnights[0], TrainerController->WhiteKnights[0]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);

}

void UKingsIndianDefenceUserWidget::StepThreeToSelect_VariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);

	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepSelectVariationToThreeClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVToSelectVariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVWP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVWP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVWP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVWP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVBP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVBP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVBP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVBP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepSVToSelectVariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepFPAWP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPAWP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPAWP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPAWP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPABP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPABP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPABP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPABP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFPAToSelectVariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPetrosianVariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepPVTxt->SetVisibility(ESlateVisibility::Visible);
	StepPV1Txt->SetVisibility(ESlateVisibility::Visible);
	StepPVWP1->SetVisibility(ESlateVisibility::Visible);
	StepPVWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepPVWP2->SetVisibility(ESlateVisibility::Visible);
	StepPVWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepPVBP1->SetVisibility(ESlateVisibility::Visible);
	StepPVBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepPVBP2->SetVisibility(ESlateVisibility::Visible);
	StepPVBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepPVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	PV_Main->SetVisibility(ESlateVisibility::Visible);
	PV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	PV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepSamischVariationClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Visible);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);

	StepSVTxt->SetVisibility(ESlateVisibility::Visible);
	StepSV1Txt->SetVisibility(ESlateVisibility::Visible);
	StepSVWP1->SetVisibility(ESlateVisibility::Visible);
	StepSVWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSVWP2->SetVisibility(ESlateVisibility::Visible);
	StepSVWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSVBP1->SetVisibility(ESlateVisibility::Visible);
	StepSVBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSVBP2->SetVisibility(ESlateVisibility::Visible);
	StepSVBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	SV_Main->SetVisibility(ESlateVisibility::Visible);
	SV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	SV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepFourPawnsAttackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Hidden);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Visible);

	StepFPATxt->SetVisibility(ESlateVisibility::Visible);
	StepFPA1Txt->SetVisibility(ESlateVisibility::Visible);
	StepFPAWP1->SetVisibility(ESlateVisibility::Visible);
	StepFPAWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepFPAWP2->SetVisibility(ESlateVisibility::Visible);
	StepFPAWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepFPABP1->SetVisibility(ESlateVisibility::Visible);
	StepFPABP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepFPABP2->SetVisibility(ESlateVisibility::Visible);
	StepFPABP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepFPAToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	FPA_Main->SetVisibility(ESlateVisibility::Visible);
	FPA_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	FPA_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::StepPVWP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVWP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVWP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVWP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVBP1Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVBP1ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVBP2Clicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::StepPVBP2ToBackClicked()
{
	KIDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	PetrosianVariation->SetVisibility(ESlateVisibility::Visible);
	SamischVariation->SetVisibility(ESlateVisibility::Hidden);
	FourPawnsAttack->SetVisibility(ESlateVisibility::Hidden);
}

