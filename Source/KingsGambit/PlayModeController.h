// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ActorBase.h"
#include "PlayModeController.generated.h"

class AChessPlayer;
class AChessBoard;
class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API APlayModeController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APlayModeController();

	//Methods
	UFUNCTION()
	void LeftMouseButtonClicked();

	UFUNCTION()
	void RightMouseButtonClicked();

	UFUNCTION()
	void SelectPiece();

	UFUNCTION()
	void HighlightSelectableGrids();

	UFUNCTION()
	void ResetGridMaterials();

	UFUNCTION()
	void ResetPieceMaterials();

	UFUNCTION()
	void SpawnWhiteActors();

	UFUNCTION()
	void SpawnBlackActors();

	UFUNCTION()
	void SwitchPlayer();

	UFUNCTION()
	AChessPlayer* GetCurrentPlayer();

	UFUNCTION()
	void MakeMove();

	UFUNCTION()
	void CancelMove();

	void DisplayErrorMessage(FText Message);
	//End of Methods

	//Variables
	TArray<UStaticMeshComponent*> SelectableGrids;
	TArray<AActorBase*> EliminatePieces;
	TArray<AActor*> OverlappedActors;
	TArray<class UPrimitiveComponent*> OverlappedComponents;
	TArray<class UMaterial*> DefaultMaterials;

	bool bChessPieceSelected = false;

	AChessBoard* ChessBoard; //Stores chessboard
	AActorBase* SelectedPiece; //Stores selected piece
	UStaticMeshComponent* SelectedGrid; //stores grid to move to

	UPROPERTY()
		AChessPlayer* PlayerOne;

	UPROPERTY()
		AChessPlayer* PlayerTwo;

	UPROPERTY()
		AChessPlayer* PreviousPlayer;

	UPROPERTY()
		AChessPlayer* CurrentPlayer;

	UPROPERTY(VisibleAnywhere)
		class UMaterial* SelectedMaterial;

	UPROPERTY()
		bool bGamePending = false;

	UPROPERTY()
		FVector GridLocation;

	UPROPERTY()
		FText ErrorMessage = FText::FromString("No Error");

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	//Dummy values to estimate spawn point. Configured in Blueprints
	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FVector ChessBoardLocation = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FRotator ChessBoardRotation = FRotator(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FVector PlayerOneLocation = FVector(1600.0, -500.0, 1500);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FRotator PlayerOneRotation = FRotator(20.0f, 90.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FVector PlayerTwoLocation = FVector(1600.0, 3700.0, 1500);

	UPROPERTY(EditAnywhere, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	FRotator PlayerTwoRotation = FRotator(20.0f, -90.0f, 0.0f);
};
