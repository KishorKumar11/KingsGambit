// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ActorBase.h"
#include "TrainerController.generated.h"

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API ATrainerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
		void SpawnWhiteActors();

	UFUNCTION()
		void SpawnBlackActors();

	UFUNCTION()
		void Move(AActorBase* PieceToMove, FVector MoveTo);

	UFUNCTION()
		void ResetAllPieces();

	UFUNCTION()
		void HighlightPiece(AActorBase* Piece);

	TArray<AActorBase*>WhitePawns;
	TArray<AActorBase*>BlackPawns;
	TArray<AActorBase*>WhiteRooks;
	TArray<AActorBase*>BlackRooks;
	TArray<AActorBase*>WhiteKnights;
	TArray<AActorBase*>BlackKnights;
	TArray<AActorBase*>WhiteBishops;
	TArray<AActorBase*>BlackBishops;

	//Pointer to chess pieces to store in arrays
	AActorBase* Pawn; 
	AActorBase* Rook1;
	AActorBase* Rook2;
	AActorBase* Knight1;
	AActorBase* Knight2;
	AActorBase* Bishop1;
	AActorBase* Bishop2;
	AActorBase* WhiteKing;
	AActorBase* BlackKing;
	AActorBase* WhiteQueen;
	AActorBase* BlackQueen;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Dummy values to estimate spawn point. Configured in Blueprints
	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FVector ChessBoardLocation = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FRotator ChessBoardRotation = FRotator(0.f, 0.f, 0.f);
};
