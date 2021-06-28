// King's Gambit by Jonathan Mui and Kishor Kumar


#include "KingPiece.h"
#include "CollisionChecker.h"
#include "ChessBoard.h"
#include "PlayModeController.h"

AKingPiece::AKingPiece()
{
	//Set the static mesh to pawn mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Meshes/SM_King.SM_King'"));
	if (FoundMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(FoundMesh.Object);
	}
}

void AKingPiece::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	FVector SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0);

	CheckOverlap(SpawnLocation + FVector(400.f, 0.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-400.f, 0.f, 0.f), SelectableGrids, DefaultMaterials);

	CheckOverlap(SpawnLocation + FVector(0.f, 400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(0.f, -400.f, 0.f), SelectableGrids, DefaultMaterials);

	CheckOverlap(SpawnLocation + FVector(400.f, 400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-400.f, -400.f, 0.f), SelectableGrids, DefaultMaterials);

	CheckOverlap(SpawnLocation + FVector(400.f, -400.f, 0.f), SelectableGrids, DefaultMaterials);
	CheckOverlap(SpawnLocation + FVector(-400.f, 400.f, 0.f), SelectableGrids, DefaultMaterials);
}

void AKingPiece::CheckOverlap(FVector SpawnLocation, TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials) 
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

	if (OverlappedComponents.Num() != 0 && OverlappedActors.Num() != 0) {
		AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
	}
	CollisionChecker->Destroy();
}

void AKingPiece::AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents)
{
	if (OverlappedActors->Num() > 1) {
		for (auto Actor : *OverlappedActors) {
			if (Actor->IsA(AActorBase::StaticClass())) {
				AActorBase* ChessPiece = Cast<AActorBase>(Actor);
				if (ChessPiece != nullptr) {
					if (bIsWhite == ChessPiece->bIsWhite) {
						//If chess piece same colour as king, break loop and return
						return;
					}
				}
			}
		}
	}

	for (auto Actor : *OverlappedActors) {
		if (Actor->IsA(AChessBoard::StaticClass())) {
			AChessBoard* ChessBoard = Cast<AChessBoard>(Actor);
			if (ChessBoard != nullptr) {
				for (auto Component : *OverlappedComponents) {
					AActor* AttachmentActor = Component->GetAttachmentRootActor();
					if (AttachmentActor->IsA(AChessBoard::StaticClass())) {
						UStaticMeshComponent* GridMesh = Cast<UStaticMeshComponent>(Component);
						if (GridMesh != nullptr) {
							SelectableGrids->Add(GridMesh);

							UMaterial* CastedMaterial = Cast<UMaterial>(GridMesh->GetMaterial(0));
							if (CastedMaterial) {
								DefaultMaterials->Add(CastedMaterial);
							}
							ChessBoard->HighlightGrid(GridMesh);
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