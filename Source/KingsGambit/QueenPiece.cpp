// King's Gambit by Jonathan Mui and Kishor Kumar


#include "QueenPiece.h"
#include "CollisionChecker.h"
#include "ChessBoard.h"
#include "PlayModeController.h"

AQueenPiece::AQueenPiece()
{
	//Set the static mesh to pawn mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Meshes/SM_Queen.SM_Queen'"));
	if (FoundMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(FoundMesh.Object);
	}
}

void AQueenPiece::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	FVector SpawnLocation; //Locations to spawn collision checker box
	TArray<AActor*> OverlappedActors; //Array to store overlapped actors
	TArray<UPrimitiveComponent*> OverlappedComponents; //Array to store overlapped components

	float deltaX = 400.f;
	float deltaY = 0.f;

	//Same as castle selectable grids
	//Search for selectable grids in 4 directions: +X, -X, +Y, -Y
	for (int32 i = 0; i < 4; i++) {
		//Reset spawn location to where chess piece is currently at
		SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0);
		//Update search coordinate value change every iteration
		if (i == 1) {
			deltaX = -400.f;
		}
		else if (i == 2) {
			deltaX = 0;
			deltaY = 400.f;
		}
		else if (i == 3) {
			deltaY = -400.f;
		}

		while (1) {
			bool bOwnPieceDetected = false;
			bool bEnemyDetected = false;

			//Spawn collision box at every grid detected
			SpawnLocation += FVector(deltaX, deltaY, 0);
			AActor* CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);

			//Get overlapped actors and components
			CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AChessBoard>());
			CollisionChecker->GetOverlappingComponents(OverlappedComponents);

			//If nothing is overlapped, break the loop and destroy collision checker
			if (OverlappedComponents.Num() == 0 && OverlappedActors.Num() == 0) {
				CollisionChecker->Destroy();
				break;
			}
			//Checks if 1 of your own piece blocks movement of rook
			else if (OverlappedActors.Num() > 1) {
				for (auto Actor : OverlappedActors) {
					if (Actor->IsA(AActorBase::StaticClass())) {
						AActorBase* ChessPiece = Cast<AActorBase>(Actor);
						if (ChessPiece != nullptr) {
							if (bIsWhite == ChessPiece->bIsWhite) {
								bOwnPieceDetected = true;
							}
							else if (bIsWhite != ChessPiece->bIsWhite) {
								bEnemyDetected = true;
							}
						}
					}
				}
			}
			//If 1 of your own pieces block rook's movement, break loop and end search for available grids
			if (bOwnPieceDetected) {
				CollisionChecker->Destroy();
				break;
			}

			AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);

			//If 1 of enemiy's pieces block rook's movement, break loop and end search for available grids
			if (bEnemyDetected) {
				CollisionChecker->Destroy();
				break;
			}

			CollisionChecker->Destroy();
		}
	}

	//Same as bishop selectable grids
	deltaX = 400.f;
	deltaY = 400.f;

	//Loop through 4 axis to search for selectable grids
	for (int32 i = 0; i < 4; ++i) {
		//Where current bishop piece is on the board
		SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0);

		//Change CollisionBox spawn location deltas in every iteration of for loop
		if (i == 1) { deltaX = -400.f; }
		else if (i == 2) { deltaY = -400.f; }
		else if (i == 3) { deltaX = 400.f; }

		//Spawn CollisionBox till it doesn't overlap anything (not on the board)
		while (1) {
			bool bOwnPieceDetected = false;
			bool bEnemyDetected = false;

			SpawnLocation += FVector(deltaX, deltaY, 0);
			//Spawn collision box
			AActor* CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
			//Get overlapped actors by collision box
			CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AChessBoard>());
			//Get overlapped components by collision box
			CollisionChecker->GetOverlappingComponents(OverlappedComponents);

			//If colisionBox does not overlap anything, break loop (means no longer on board)
			if (OverlappedComponents.Num() == 0 && OverlappedActors.Num() == 0) {
				CollisionChecker->Destroy();
				break;
			}
			//If there is another piece of the same colour that blocks the bishop's path
			else if (OverlappedActors.Num() > 1) {
				for (auto Actor : OverlappedActors) {
					if (Actor->IsA(AActorBase::StaticClass())) {
						AActorBase* ChessPiece = Cast<AActorBase>(Actor);
						if (ChessPiece != nullptr) {
							if (bIsWhite == ChessPiece->bIsWhite) {
								bOwnPieceDetected = true;
							}
							else if (bIsWhite != ChessPiece->bIsWhite) {
								bEnemyDetected = true;
							}
						}
					}
				}
			}
			//If own piece is blocking bishop's path, exit loop
			if (bOwnPieceDetected) {
				CollisionChecker->Destroy();
				break;
			}
			AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
			//If enemy piece blocking bishop's path, exit loop
			if (bEnemyDetected) {
				CollisionChecker->Destroy();
				break;
			}
			CollisionChecker->Destroy();
		}
	}
}

void AQueenPiece::AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents)
{
	/* 1. Check every overlapped actor. If overlapped actor is a grid, add it to SelectableGrids array and it's material to DefaultMaterials array
	* If it's a chess piece, change piece's material
	*/
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