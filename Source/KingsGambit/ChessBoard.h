// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessBoard.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UMaterial;

UCLASS()
class KINGSGAMBIT_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	//Methods starting with constructor:

	// Sets default values for this actor's properties
	AChessBoard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HighlightGrid(UStaticMeshComponent* Grid);

	//Variables:

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere)
	TArray<UStaticMeshComponent*> GridSquares;

	UPROPERTY(EditAnywhere)
	UMaterial* WhiteMaterial;

	UPROPERTY(EditAnywhere)
	UMaterial* BlackMaterial;

	UPROPERTY(EditAnywhere)
	UMaterial* HighlightedMaterial;

	UPROPERTY()
	UMaterial* DefaultMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
