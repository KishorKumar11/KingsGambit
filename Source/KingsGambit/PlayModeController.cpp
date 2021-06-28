// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PlayModeController.h"
#include "Blueprint/UserWidget.h"
#include "Components/StaticMeshComponent.h"
#include "PlayModeHUD.h"
#include "KingPiece.h"
#include "QueenPiece.h"
#include "BishopPiece.h"
#include "KnightPiece.h"
#include "CastlePiece.h"
#include "PawnPiece.h"
#include "ChessBoard.h"
#include "ChessPlayer.h"
#include "CollisionChecker.h"

APlayModeController::APlayModeController()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> Material1(TEXT("Material'/Game/TexturesAndMaterials/M_SelectedMaterial.M_SelectedMaterial'"));
	if (Material1.Object != NULL) {
		SelectedMaterial = Material1.Object;
	}
}

void APlayModeController::BeginPlay()
{
	Super::BeginPlay();
	SetShowMouseCursor(true);

	ChessBoard = GetWorld()->SpawnActor<AChessBoard>(ChessBoardLocation, ChessBoardRotation);

	PlayerTwo = GetWorld()->SpawnActor<AChessPlayer>(PlayerTwoLocation, PlayerTwoRotation);
	PlayerTwo->bIsWhite = false;
	PlayerOne = GetWorld()->SpawnActor<AChessPlayer>(PlayerOneLocation, PlayerOneRotation);
	PlayerOne->bIsWhite = true;
	CurrentPlayer = PlayerOne;
	PreviousPlayer = PlayerOne;

	PlayerOne->SetName(FText::FromString("PlayerOne"));
	PlayerTwo->SetName(FText::FromString("PlayerTwo"));

	//Spawn chess pieces
	SpawnWhiteActors();
	SpawnBlackActors();
}

void APlayModeController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind actions to input from computer
	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &APlayModeController::LeftMouseButtonClicked);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &APlayModeController::RightMouseButtonClicked);
}

void APlayModeController::LeftMouseButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Left Click works"));

	if (bGamePending) { return; } //Don't run if game pending

	//Clear previous selection
	if (this->SelectedPiece != nullptr) {
		this->SelectedPiece->SetDefaultMaterial();
	}

	ResetGridMaterials();
	ResetPieceMaterials();

	SelectPiece();
}

void APlayModeController::RightMouseButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Right Click works"));

	if (bGamePending) { return; } //Don't run if game pending

	ResetGridMaterials();
	ResetPieceMaterials();

	//Check if any chess piece is selected. Only execute code if items are selected.
	if (bChessPieceSelected) {
		//Detect clicked area(hit result), stores it in TraceResult
		FHitResult TraceResult(ForceInit);
		GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
		if (TraceResult.GetComponent() != nullptr) {
			SelectedGrid = Cast<UStaticMeshComponent>(TraceResult.GetComponent());
			if (SelectedGrid != nullptr) {
				//Check if selected grid is a grid in SelectableGrids
				for (auto Grid : SelectableGrids) {
					if (Grid->GetComponentLocation() == SelectedGrid->GetComponentLocation()) {
						GridLocation = SelectedGrid->GetComponentLocation() + FVector(0.f, 0.f, 0.5f);
						APlayModeHUD* CastedHUD = Cast<APlayModeHUD>(GetHUD());
						if (CastedHUD != nullptr) {
							SelectedGrid->SetMaterial(0, SelectedMaterial);
							CastedHUD->Widget->SetButtonVisibility(true);
						}
						
						return;
					}
				}
				//Display error message: Can't make move here
				DisplayErrorMessage(FText::FromString("Can't make a move there!"));
			}
		}
	}
}

void APlayModeController::SelectPiece()
{
	//Detect clicked area(hit result), stores it in TraceResult
	FHitResult TraceResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);

	//If item clicked is an actor
	if (TraceResult.GetActor() != nullptr) {
		//if item clicked is ActorBase (aka chesspiece)
		if (TraceResult.GetActor()->IsA(AActorBase::StaticClass())) {
			SelectedPiece = Cast<AActorBase>(TraceResult.GetActor()); //Cast clicked actor to ActorBase
			//Check if casting successful
			if (SelectedPiece != nullptr) {
				if (SelectedPiece->bIsWhite == CurrentPlayer->bIsWhite) {
					SelectedPiece->SetHighlightedMaterial();
					bChessPieceSelected = true;
					HighlightSelectableGrids();
					return;
				}
				else {
					//Display something that says can't select enemy's piece
					DisplayErrorMessage(FText::FromString("Can't select enemy's piece!"));
				}
			}
		}
	}
	bChessPieceSelected = false;
}

void APlayModeController::HighlightSelectableGrids()
{
	//Empty Previous Records
	SelectableGrids.Empty();
	DefaultMaterials.Empty();
	EliminatePieces.Empty();

	SelectedPiece->DetectSelectableGrids(&SelectableGrids, &DefaultMaterials);
}

void APlayModeController::ResetGridMaterials()
{
	for (int32 index = 0; index < SelectableGrids.Num(); index++) {
		SelectableGrids[index]->SetMaterial(0, DefaultMaterials[index]);
	}
}

void APlayModeController::ResetPieceMaterials()
{
	for (int32 index = 0; index < EliminatePieces.Num(); index++) {
		EliminatePieces[index]->SetDefaultMaterial();
	}
}

void APlayModeController::SpawnWhiteActors()
{
	TArray<class AActorBase*>SpawnedPieces;
	
	//Set pawn location
	for (int32 i = 1; i <= 8; i++) {
		SpawnedPieces.Add(GetWorld()->SpawnActor<APawnPiece>(
			FVector(400.f, (i * 400.f) - 400.f, 0.5f),
			FRotator::ZeroRotator));
	}

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKingPiece>(
		FVector(0.f, 1600.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ACastlePiece>(
		FVector(0.f, 0.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ACastlePiece>(
		FVector(0.f, 2800.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKnightPiece>(
		FVector(0.f, 400.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKnightPiece>(
		FVector(0.f, 2400.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ABishopPiece>(
		FVector(0.f, 800.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ABishopPiece>(
		FVector(0.f, 2000.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AQueenPiece>(
		FVector(0.f, 1200.f, 200.f),
		FRotator::ZeroRotator
		));

	for (auto Piece : SpawnedPieces) {
		Piece->bIsWhite = true;
		Piece->SetDefaultMaterial();
	}
	PlayerOne->Pieces = SpawnedPieces;
	SpawnedPieces.Empty();
}

void APlayModeController::SpawnBlackActors()
{
	TArray<class AActorBase*>SpawnedPieces;

	//Set pawn location
	for (int32 i = 1; i <= 8; i++) {
		SpawnedPieces.Add(GetWorld()->SpawnActor<APawnPiece>(
			FVector(2400.f, (i * 400.f) - 400.f, 0.5f),
			FRotator::ZeroRotator
			));
	}

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKingPiece>(
		FVector(2800.f, 1600.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ACastlePiece>(
		FVector(2800.f, 0.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ACastlePiece>(
		FVector(2800.f, 2800.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKnightPiece>(
		FVector(2800.f, 400.f, 200.f),
		FRotator(0.f ,180.f ,0.f)
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AKnightPiece>(
		FVector(2800.f, 2400.f, 200.f),
		FRotator(0.f, 180.f, 0.f)
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ABishopPiece>(
		FVector(2800.f, 800.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<ABishopPiece>(
		FVector(2800.f, 2000.f, 200.f),
		FRotator::ZeroRotator
		));

	SpawnedPieces.Add(GetWorld()->SpawnActor<AQueenPiece>(
		FVector(2800.f, 1200.f, 200.f),
		FRotator::ZeroRotator
		));

	for (auto Piece : SpawnedPieces) {
		Piece->bIsWhite = false;
		Piece->SetDefaultMaterial();
	}
	PlayerTwo->Pieces = SpawnedPieces;
	SpawnedPieces.Empty();
}

void APlayModeController::SwitchPlayer()
{
	//Unpossess current player
	UnPossess();
	//switch to next player
	if (CurrentPlayer == PlayerTwo) {
		PreviousPlayer = PlayerTwo;
		CurrentPlayer = PlayerOne;
		Possess(PlayerOne);
	}
	else if (CurrentPlayer == PlayerOne) {
		PreviousPlayer = PlayerOne;
		CurrentPlayer = PlayerTwo;
		Possess(PlayerTwo);
	}
}

AChessPlayer* APlayModeController::GetCurrentPlayer()
{
	return CurrentPlayer;
}

void APlayModeController::MakeMove()
{
	AActor* CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(GridLocation, FRotator::ZeroRotator);
	CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AActor>());
	if (OverlappedActors.Num() > 1) {
		for (auto Actor : OverlappedActors) {
			if (Actor->IsA(AActorBase::StaticClass())) {
				AActorBase* ChessPiece = Cast<AActorBase>(Actor);
				if (ChessPiece) {
					ChessPiece->EliminatePiece();
				}
			}
		}
	}
	OverlappedActors.Empty();
	CollisionChecker->Destroy();

	SelectedPiece->MovePiece(FVector(GridLocation.X, GridLocation.Y, SelectedPiece->GetActorLocation().Z + 200.f));
	if (!SelectedPiece->bHasEverMoved) {
		SelectedPiece->bHasEverMoved = true;
	}
	ResetGridMaterials();
	ResetPieceMaterials();
	SwitchPlayer();
}

void APlayModeController::CancelMove()
{
	ResetGridMaterials();
	ResetPieceMaterials();
	SelectedPiece->SetDefaultMaterial();
	//Emptys Arrays
	SelectableGrids.Empty();
	EliminatePieces.Empty();
	SelectedPiece = nullptr;
}

void APlayModeController::DisplayErrorMessage(FText Message)
{
	ErrorMessage = Message;
	APlayModeHUD* CastedHUD = Cast<APlayModeHUD>(GetHUD());
	if (CastedHUD != nullptr) {
		CastedHUD->Widget->DisplayErrorMessage();
	}
}