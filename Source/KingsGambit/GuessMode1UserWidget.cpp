// King's Gambit by Jonathan Mui and Kishor Kumar


#include "GuessMode1UserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UGuessMode1UserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::QuitButtonClicked);
	OKToNotationsMode->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::OKToNotationsModeClicked);

	GameOverToMenu->OnClicked.AddUniqueDynamic(this, &UGuessMode1UserWidget::MainMenuButtonClicked);
}

void UGuessMode1UserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	GuessModeHUD->SetVisibility(ESlateVisibility::Hidden);
}

void UGuessMode1UserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	GuessModeHUD->SetVisibility(ESlateVisibility::Visible);
}

void UGuessMode1UserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UGuessMode1UserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UGuessMode1UserWidget::OKToNotationsModeClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	UserGuide_1->SetVisibility(ESlateVisibility::Hidden);
	UserGuideInterface_1->SetVisibility(ESlateVisibility::Hidden);

	GuessModeHUD->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
}





