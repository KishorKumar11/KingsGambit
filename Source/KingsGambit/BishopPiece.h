// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "ActorBase.h"
#include "BishopPiece.generated.h"

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API ABishopPiece : public AActorBase
{
	GENERATED_BODY()
	
public:
	ABishopPiece();

	/*
	* Detects Selectable Grid Squares
	* @param[in,out] SelectableGrids Pointer to array storing selectable grids
	* @param[in,out] DefaultMaterials Pointer to array storing material values of selectable grids
	*/
	void DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials);

	/*
	* Highlights every selectable grid. Also adds grid to SelectableGrids array and their default materials to DefaultMaterials array
	* @param[in,out] SelectableGrids Pointer to array storing selectable grids
	* @param[in,out] DefaultMaterials Pointer to array storing material values of selectable grids
	* @param[in,out] OverlappedActors Pointer to array storing overlapped actors (chess pieces)
	* @param[in,out] OverlappedComponents Pointer to array storing overlapped components
	*/
	void AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents);
};
