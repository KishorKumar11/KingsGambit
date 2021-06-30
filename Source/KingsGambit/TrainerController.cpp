// King's Gambit by Jonathan Mui and Kishor Kumar


#include "TrainerController.h"
#include "Blueprint/UserWidget.h"
#include "KingPiece.h"
#include "QueenPiece.h"
#include "BishopPiece.h"
#include "KnightPiece.h"
#include "CastlePiece.h"
#include "PawnPiece.h"
#include "ChessBoard.h"

void ATrainerController::BeginPlay()
{
	Super::BeginPlay();
	SetShowMouseCursor(true);

	AChessBoard* ChessBoard = GetWorld()->SpawnActor<AChessBoard>(ChessBoardLocation, ChessBoardRotation);

	//Spawn chess pieces
	SpawnWhiteActors();
	SpawnBlackActors();
}

void ATrainerController::SpawnWhiteActors()
{
	TArray<AActorBase*>SpawnedPieces;

	//Set pawn location
	for (int32 i = 1; i <= 8; i++) {
		Pawn = GetWorld()->SpawnActor<APawnPiece>(
			FVector(400.f, (i * 400.f) - 400.f, 0.5f),
			FRotator::ZeroRotator);
		
		Pawn->OriginalSpawnLocation = FVector(400.f, (i * 400.f) - 400.f, 0.5f);
		SpawnedPieces.Add(Pawn);
		WhitePawns.Add(Pawn);
	}

	WhiteKing = GetWorld()->SpawnActor<AKingPiece>(
		FVector(0.f, 1600.f, 200.f),
		FRotator::ZeroRotator
		);
	WhiteKing->OriginalSpawnLocation = FVector(0.f, 1600.f, 200.f);
	SpawnedPieces.Add(WhiteKing);

	Rook1 = GetWorld()->SpawnActor<ACastlePiece>(
		FVector(0.f, 0.f, 200.f),
		FRotator::ZeroRotator
		);
	Rook1->OriginalSpawnLocation = FVector(0.f, 0.f, 200.f);
	SpawnedPieces.Add(Rook1);
	WhiteRooks.Add(Rook1);

	Rook2 = GetWorld()->SpawnActor<ACastlePiece>(
		FVector(0.f, 2800.f, 200.f),
		FRotator::ZeroRotator
		);
	Rook2->OriginalSpawnLocation = FVector(0.f, 0.f, 200.f);
	SpawnedPieces.Add(Rook2);
	WhiteRooks.Add(Rook2);

	Knight1 = GetWorld()->SpawnActor<AKnightPiece>(
		FVector(0.f, 400.f, 200.f),
		FRotator::ZeroRotator
		);
	Knight1->OriginalSpawnLocation = FVector(0.f, 400.f, 200.f);
	SpawnedPieces.Add(Knight1);
	WhiteKnights.Add(Knight1);

	Knight2 = GetWorld()->SpawnActor<AKnightPiece>(
		FVector(0.f, 2400.f, 200.f),
		FRotator::ZeroRotator
		);
	Knight2->OriginalSpawnLocation = FVector(0.f, 2400.f, 200.f);
	SpawnedPieces.Add(Knight2);
	WhiteKnights.Add(Knight2);

	Bishop1 = GetWorld()->SpawnActor<ABishopPiece>(
		FVector(0.f, 800.f, 200.f),
		FRotator::ZeroRotator
		);
	Bishop1->OriginalSpawnLocation = FVector(0.f, 800.f, 200.f);
	SpawnedPieces.Add(Bishop1);
	WhiteBishops.Add(Bishop1);

	Bishop2 = GetWorld()->SpawnActor<ABishopPiece>(
		FVector(0.f, 2000.f, 200.f),
		FRotator::ZeroRotator
		);
	Bishop2->OriginalSpawnLocation = FVector(0.f, 2000.f, 200.f);
	SpawnedPieces.Add(Bishop2);
	WhiteBishops.Add(Bishop2);

	WhiteQueen = GetWorld()->SpawnActor<AQueenPiece>(
		FVector(0.f, 1200.f, 200.f),
		FRotator::ZeroRotator
		);
	WhiteQueen->OriginalSpawnLocation = FVector(0.f, 1200.f, 200.f);
	SpawnedPieces.Add(WhiteQueen);

	for (auto Piece : SpawnedPieces) {
		Piece->bIsWhite = true;
		Piece->SetDefaultMaterial();
	}

	SpawnedPieces.Empty();
}

void ATrainerController::SpawnBlackActors()
{
	TArray<AActorBase*>SpawnedPieces;

	//Set pawn location
	for (int32 i = 1; i <= 8; i++) {
		Pawn = GetWorld()->SpawnActor<APawnPiece>(
			FVector(2400.f, (i * 400.f) - 400.f, 0.5f),
			FRotator::ZeroRotator);
		Pawn->OriginalSpawnLocation = FVector(2400.f, (i * 400.f) - 400.f, 0.5f);
		SpawnedPieces.Add(Pawn);
		BlackPawns.Add(Pawn);
	}

	BlackKing = GetWorld()->SpawnActor<AKingPiece>(
		FVector(2800.f, 1600.f, 200.f),
		FRotator::ZeroRotator
		);
	BlackKing->OriginalSpawnLocation = FVector(2800.f, 1600.f, 200.f);
	SpawnedPieces.Add(WhiteKing);

	Rook1 = GetWorld()->SpawnActor<ACastlePiece>(
		FVector(2800.f, 0.f, 200.f),
		FRotator::ZeroRotator
		);
	Rook1->OriginalSpawnLocation = FVector(2800.f, 0.f, 200.f);
	SpawnedPieces.Add(Rook1);
	BlackRooks.Add(Rook1);

	Rook2 = GetWorld()->SpawnActor<ACastlePiece>(
		FVector(2800.f, 2800.f, 200.f),
		FRotator::ZeroRotator
		);
	Rook2->OriginalSpawnLocation = FVector(2800.f, 2800.f, 200.f);
	SpawnedPieces.Add(Rook2);
	BlackRooks.Add(Rook2);

	Knight1 = GetWorld()->SpawnActor<AKnightPiece>(
		FVector(2800.f, 400.f, 200.f),
		FRotator(0.f, 180.f, 0.f)
		);
	Knight1->OriginalSpawnLocation = FVector(2800.f, 400.f, 200.f);
	SpawnedPieces.Add(Knight1);
	BlackKnights.Add(Knight1);

	Knight2 = GetWorld()->SpawnActor<AKnightPiece>(
		FVector(2800.f, 2400.f, 200.f),
		FRotator(0.f, 180.f, 0.f)
		);
	Knight2->OriginalSpawnLocation = FVector(2800.f, 2400.f, 200.f);
	SpawnedPieces.Add(Knight2);
	BlackKnights.Add(Knight2);

	Bishop1 = GetWorld()->SpawnActor<ABishopPiece>(
		FVector(2800.f, 800.f, 200.f),
		FRotator::ZeroRotator
		);
	Bishop1->OriginalSpawnLocation = FVector(2800.f, 800.f, 200.f);
	SpawnedPieces.Add(Bishop1);
	BlackBishops.Add(Bishop1);

	Bishop2 = GetWorld()->SpawnActor<ABishopPiece>(
		FVector(2800.f, 2000.f, 200.f),
		FRotator::ZeroRotator
		);
	Bishop2->OriginalSpawnLocation = FVector(2800.f, 2000.f, 200.f);
	SpawnedPieces.Add(Bishop2);
	BlackBishops.Add(Bishop2);

	BlackQueen = GetWorld()->SpawnActor<AQueenPiece>(
		FVector(2800.f, 1200.f, 200.f),
		FRotator::ZeroRotator
		);
	BlackQueen->OriginalSpawnLocation = FVector(2800.f, 1200.f, 200.f);
	SpawnedPieces.Add(BlackQueen);

	for (auto Piece : SpawnedPieces) {
		Piece->bIsWhite = false;
		Piece->SetDefaultMaterial();
	}

	SpawnedPieces.Empty();
}

void ATrainerController::Move(AActorBase* PieceToMove, FVector MoveTo)
{
	PieceToMove->MovePiece(MoveTo);
}

//Causes Memory Leak DON'T USE
void ATrainerController::ResetAllPieces()
{
	for (auto Piece : WhitePawns) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : BlackPawns) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : WhiteRooks) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : BlackRooks) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : WhiteKnights) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : BlackKnights) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : WhiteBishops) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	for (auto Piece : BlackBishops) {
		Move(Piece, Piece->OriginalSpawnLocation);
	}
	Move(WhiteKing, WhiteKing->OriginalSpawnLocation);
	Move(BlackKing, BlackKing->OriginalSpawnLocation);
	Move(WhiteQueen, WhiteQueen->OriginalSpawnLocation);
	Move(BlackQueen, BlackQueen->OriginalSpawnLocation);
}