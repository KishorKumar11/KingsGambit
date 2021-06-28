// King's Gambit by Jonathan Mui and Kishor Kumar


#include "BishopPiece.h"
#include "CollisionChecker.h"
#include "ChessBoard.h"
#include "PlayModeController.h"

ABishopPiece::ABishopPiece()
{
	//Set the static mesh to pawn mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Meshes/SM_Bishop.SM_Bishop'"));
	if (FoundMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(FoundMesh.Object);
	}
}

void ABishopPiece::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	FVector SpawnLocation; //Locations to spawn collision checker box
	TArray<AActor*> OverlappedActors; //Array to store overlapped actors
	TArray<UPrimitiveComponent*> OverlappedComponents; //Array to store overlapped components
	//Values to alter x and y axis
	float deltaX = 400.f;
	float deltaY = 400.f;

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

void ABishopPiece::AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents)
{
	for (auto Actor : *OverlappedActors) {
		//If overlapped actor is a board grid
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

		//If overlapped actor is a chess piece
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