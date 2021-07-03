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

	SetLevel(1);
}

void UGuessMode1UserWidget::ResetTextboxesAndEnterButtons()
{
	Answer1->SetVisibility(ESlateVisibility::Visible);
	Enter1->SetVisibility(ESlateVisibility::Visible);
	Answer2->SetVisibility(ESlateVisibility::Hidden);
	Enter2->SetVisibility(ESlateVisibility::Hidden);
	Answer3->SetVisibility(ESlateVisibility::Hidden);
	Enter3->SetVisibility(ESlateVisibility::Hidden);
	Answer4->SetVisibility(ESlateVisibility::Hidden);
	Enter4->SetVisibility(ESlateVisibility::Hidden);
	Answer5->SetVisibility(ESlateVisibility::Hidden);
	Enter5->SetVisibility(ESlateVisibility::Hidden);
	Answer6->SetVisibility(ESlateVisibility::Hidden);
	Enter6->SetVisibility(ESlateVisibility::Hidden);
	Answer7->SetVisibility(ESlateVisibility::Hidden);
	Enter7->SetVisibility(ESlateVisibility::Hidden);
	Answer8->SetVisibility(ESlateVisibility::Hidden);
	Enter8->SetVisibility(ESlateVisibility::Hidden);
	Answer9->SetVisibility(ESlateVisibility::Hidden);
	Enter9->SetVisibility(ESlateVisibility::Hidden);
	Answer10->SetVisibility(ESlateVisibility::Hidden);
	Enter10->SetVisibility(ESlateVisibility::Hidden);
}

void UGuessMode1UserWidget::SetLevel(int32 level)
{
	switch (level) {
		case 1:
			TrainerController->ResetAllPieces();
			TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
			Answer1->SetVisibility(ESlateVisibility::Visible);
			Enter1->SetVisibility(ESlateVisibility::Visible);
			break;

		case 2:

			//Reset pieces moved from lvl 1
			TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
			TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));
			Answer1->SetVisibility(ESlateVisibility::Hidden);
			Enter1->SetVisibility(ESlateVisibility::Hidden);
			Answer2->SetVisibility(ESlateVisibility::Visible);
			Enter2->SetVisibility(ESlateVisibility::Visible);
			break;

		case 3:
			//Reset Pieces moved from lvl 2
			TrainerController->Move(TrainerController->WhiteKnights[1], TrainerController->WhiteKnights[1]->OriginalSpawnLocation);

			TrainerController->Move(TrainerController->BlackBishops[0], FVector(1200.f, 2400.f, 0.5f));
			TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));
			Answer2->SetVisibility(ESlateVisibility::Hidden);
			Enter2->SetVisibility(ESlateVisibility::Hidden);
			Answer3->SetVisibility(ESlateVisibility::Visible);
			Enter3->SetVisibility(ESlateVisibility::Visible);
			break;

		case 4:
			//Reset Pieces moved from lvl 3
			TrainerController->Move(TrainerController->BlackBishops[0], TrainerController->BlackBishops[0]->OriginalSpawnLocation);
			TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);

			TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
			TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));
			TrainerController->Move(TrainerController->WhiteQueen, FVector(1600.f, 2800.f, 0.5f));


			Answer3->SetVisibility(ESlateVisibility::Hidden);
			Enter3->SetVisibility(ESlateVisibility::Hidden);
			Answer4->SetVisibility(ESlateVisibility::Visible);
			Enter4->SetVisibility(ESlateVisibility::Visible);
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			break;
		
		default:
			return;
	}
}





