// King's Gambit by Jonathan Mui and Kishor Kumar


#include "KnightPiece.h"
#include "CollisionChecker.h"
#include "ChessBoard.h"
#include "PlayModeController.h"

AKnightPiece::AKnightPiece()
{
	//Set the static mesh to pawn mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Meshes/SM_Knight.SM_Knight'"));
	if (FoundMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(FoundMesh.Object);
	}
}

void AKnightPiece::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	FVector SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0);
	CheckOverlap(SpawnLocation + FVector(400.f, 800.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(400.f, -800.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-400.f, 800.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-400.f, -800.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(800.f, 400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(800.f, -400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-800.f, 400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-800.f, -400.f, 0.f), SelectableGrids, DefaultMaterials);
}

void AKnightPiece::CheckOverlap(FVector SpawnLocation, TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	//Holds overlapped Actors
	TArray<AActor*> OverlappedActors;
	//Holds overlapped components
	TArray<UPrimitiveComponent*> OverlappedComponents;
	//Spawn collision box
	AActor* CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
	//Get overlapped actors by collision box
	CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AChessBoard>());
	//Get overlapped components by collision box
	CollisionChecker->GetOverlappingComponents(OverlappedComponents);

	//Destroys detected selectable grids not on the board
	if (OverlappedComponents.Num() == 0 && OverlappedActors.Num() == 0) {
		CollisionChecker->Destroy();
		return;
	}

	AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
	CollisionChecker->Destroy();
}

void AKnightPiece::AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents)
{
	//Check if there is chess piece on target grid and check if it's enemy's piece. If not enemy's piece, can't move there
	if (OverlappedActors->Num() > 1) {
		for (auto Actor : *OverlappedActors) {
			if (Actor->IsA(AActorBase::StaticClass())) {
				AActorBase* ChessPiece = Cast<AActorBase>(Actor);
				if (ChessPiece != nullptr) {
					if (bIsWhite == ChessPiece->bIsWhite) {
						return; //Chesss piece on supposed selectable grid is your piece
					}
				}
			}
		}
	}

	//If chessboard grid has no chess pieces on it, highlight grid
	for (auto Actor : *OverlappedActors) {
		if (Actor->IsA(AChessBoard::StaticClass())) {
			AChessBoard* ChessBoard = Cast<AChessBoard>(Actor);
			if (ChessBoard != nullptr) { //check if cast successful
				for (auto Component : *OverlappedComponents) {
					AActor* AttachmentActor = Component->GetAttachmentRootActor();
					if (AttachmentActor->IsA(AChessBoard::StaticClass())) {
						// Cast component to StaticMeshComponent
						UStaticMeshComponent* CastedMesh = Cast<UStaticMeshComponent>(Component);
						if (CastedMesh != nullptr) {
							//Add Grid to SelectableGrids
							SelectableGrids->Add(CastedMesh);

							//Add Material types of selectable grids to array to switch between materials
							UMaterial* CastedMaterial = Cast<UMaterial>(CastedMesh->GetMaterial(0));
							if (CastedMaterial) {
								//Add Grid's current material (either black or white) to the DefaultMaterials array
								DefaultMaterials->Add(CastedMaterial);
							}
							ChessBoard->HighlightGrid(CastedMesh); //Highlights grid square
						}
					}
				}
			}
		}
		else if (Actor->IsA(AActorBase::StaticClass())) {
			AActorBase* ChessPiece = Cast<AActorBase>(Actor);
			if (ChessPiece != nullptr) {
				APlayModeController* PlayModeController = Cast<APlayModeController>(GetWorld()->GetFirstPlayerController());
				if (PlayModeController != nullptr) {
					PlayModeController->EliminatePieces.Add(ChessPiece);
					ChessPiece->SetEliminateMaterial();
				}
			}
		}
	}
}