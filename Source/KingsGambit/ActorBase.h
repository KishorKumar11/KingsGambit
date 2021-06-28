// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorBase.generated.h"

class UStaticMeshComponent;
class UMaterial;

UCLASS()
class KINGSGAMBIT_API AActorBase : public AActor
{
	GENERATED_BODY()
	
public:
	//Methods:

	// Sets default values for this actor's properties
	AActorBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void SetDefaultMaterial();

	UFUNCTION()
		void SetHighlightedMaterial();

	UFUNCTION()
		void SetEliminateMaterial();

	UFUNCTION()
		void MovePiece(FVector MoveTo);

	UFUNCTION()
		void EliminatePiece();

	virtual void DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials);

	//Variables and Properties:

	UPROPERTY(VisibleAnywhere)
		bool bIsWhite;

	UPROPERTY(VisibleAnywhere)
		bool bHasEverMoved;

	UPROPERTY()
		FVector OriginalSpawnLocation;

	//Null by default. Overridden for every chess piece
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;

	//White Material for the piece
	UPROPERTY(EditAnywhere, Category = "Materials", meta = (AllowPrivateAccess = "true"))
		UMaterial* WhiteMaterial;

	//Black Material for the piece
	UPROPERTY(EditAnywhere, Category = "Materials", meta = (AllowPrivateAccess = "true"))
		UMaterial* BlackMaterial;

	//Material for selected piece
	UPROPERTY(EditAnywhere, Category = "Materials", meta = (AllowPrivateAccess = "true"))
		UMaterial* HighlightedMaterial;

	//Material to set when piece could be eliminated
	UPROPERTY(EditAnywhere, Category = "Materials", meta = (AllowPrivateAccess = "true"))
		UMaterial* EliminateMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};
