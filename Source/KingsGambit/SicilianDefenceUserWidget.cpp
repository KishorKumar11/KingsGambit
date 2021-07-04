// King's Gambit by Jonathan Mui and Kishor Kumar


#include "SicilianDefenceUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void USicilianDefenceUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepThreeToTwoClicked);
	StepThreeToMainMenu->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::MainMenuButtonClicked);

	NVNext->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVNextClicked);
	StepNVWP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP1Clicked);
	StepNVWP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP1ToBackClicked);
	StepNVWP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP2Clicked);
	StepNVWP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP2ToBackClicked);
	StepNVWP3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP3Clicked);
	StepNVWP3ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVWP3ToBackClicked);
	StepNVBP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP1Clicked);
	StepNVBP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP1ToBackClicked);
	StepNVBP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP2Clicked);
	StepNVBP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP2ToBackClicked);
	StepNVBP3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP3Clicked);
	StepNVBP3ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP3ToBackClicked);
	StepNVBP4->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP4Clicked);
	StepNVBP4ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepNVBP4ToBackClicked);

	ADNext->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADNextClicked);
	StepADWP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP1Clicked);
	StepADWP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP1ToBackClicked);
	StepADWP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP2Clicked);
	StepADWP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP2ToBackClicked);
	StepADWP3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP3Clicked);
	StepADWP3ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADWP3ToBackClicked);
	StepADBP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP1Clicked);
	StepADBP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP1ToBackClicked);
	StepADBP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP2Clicked);
	StepADBP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP2ToBackClicked);
	StepADBP3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP3Clicked);
	StepADBP3ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepADBP3ToBackClicked);

	CDNext->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDNextClicked);
	StepCDWP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDWP1Clicked);
	StepCDWP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDWP1ToBackClicked);
	StepCDWP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDWP2Clicked);
	StepCDWP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDWP2ToBackClicked);
	StepCDBP1->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP1Clicked);
	StepCDBP1ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP1ToBackClicked);
	StepCDBP2->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP2Clicked);
	StepCDBP2ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP2ToBackClicked);
	StepCDBP3->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP3Clicked);
	StepCDBP3ToBack->OnClicked.AddUniqueDynamic(this, &URuyLopezUserWidget::StepCDBP3ToBackClicked);
}

void USicilianDefenceUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void USicilianDefenceUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void USicilianDefenceUserWidget::StepZeroToOneClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1600.f, 800.f, 0.5f));
}

void USicilianDefenceUserWidget::StepOneToZeroClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[2], TrainerController->BlackPawns[2]->OriginalSpawnLocation);
}

void USicilianDefenceUserWidget::StepOneToTwoClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));

}

void USicilianDefenceUserWidget::StepTwoToOneClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);

}

void USicilianDefenceUserWidget::StepTwoToThreeClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1200.f, 1200.f, 0.5f));

}

void USicilianDefenceUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1600.f, 800.f, 0.5f));
}
