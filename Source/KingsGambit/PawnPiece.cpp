// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PawnPiece.h"
#include "Chessboard.h"
#include "CollisionChecker.h"
#include "PlayModeController.h"

APawnPiece::APawnPiece()
{
	//Set the static mesh to pawn mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/Meshes/SM_Pawn.SM_Pawn'"));
	if (FoundMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(FoundMesh.Object);
	}
}

void APawnPiece::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	/*1. Spawn CollisionBox to get selectable grids by collision check*/
	FVector SpawnLocation; //Locations to spawn collision checker box
	TArray<AActor*> OverlappedActors; //Array to store overlapped actors
	TArray<UPrimitiveComponent*> OverlappedComponents; //Array to store overlapped components

	/*2. Setting Pawn's normal forward move (+400 in x direction because board faces x direction)*/
	if (bIsWhite) {
		SpawnLocation = FVector(GetActorLocation().X + 400.f, GetActorLocation().Y, 0.f);
	}
	else {
		SpawnLocation = FVector(GetActorLocation().X - 400.f, GetActorLocation().Y, 0.f);
	}
	//Spawns Collision checker
	AActor* CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
	//Get overlapping actors by collision checker box
	CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AActor>());
	//Get overlapping components by collision checker box
	CollisionChecker->GetOverlappingComponents(OverlappedComponents);
	//Means chessboard is the only overlapped actor
	if (OverlappedActors.Num() == 1) {
		AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
	}
	//Clears Arrays and destroys collisionchecker actor
	OverlappedActors.Empty();
	OverlappedComponents.Empty();
	CollisionChecker->Destroy();

	/*3. Setting Pawn's double forward move*/
	if (!bHasEverMoved) {
		if (bIsWhite) {
			SpawnLocation = FVector(GetActorLocation().X + 800.f, GetActorLocation().Y, 0.f);
		}
		else {
			SpawnLocation = FVector(GetActorLocation().X - 800.f, GetActorLocation().Y, 0.f);
		}
		//Spawns Collision checker
		AActor* CollisionChecker1 = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
		//Get overlapping actors by collision checker box
		CollisionChecker1->GetOverlappingActors(OverlappedActors, TSubclassOf<AActor>());
		//Get overlapping components by collision checker box
		CollisionChecker1->GetOverlappingComponents(OverlappedComponents);
		//Means chessboard is the only overlapped actor
		if (OverlappedActors.Num() == 1) {
			AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
		}
		//Clears Arrays and destroys collisionchecker actor
		OverlappedActors.Empty();
		OverlappedComponents.Empty();
		CollisionChecker1->Destroy();
	}

	/*4. Setting Pawn's Diagonal right move*/
	if (bIsWhite) {
		SpawnLocation = FVector(GetActorLocation().X + 400.f, GetActorLocation().Y + 400.f, 0.f);
	}
	else {
		SpawnLocation = FVector(GetActorLocation().X - 400.f, GetActorLocation().Y - 400.f, 0.f);
	}
	//Spawns Collision checker
	CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
	//Get overlapping actors by collision checker box
	CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AActor>());
	//Get overlapping components by collision checker box
	CollisionChecker->GetOverlappingComponents(OverlappedComponents);
	//Means there is a chess piece on the grid square of the chess board
	if (OverlappedActors.Num() > 1) {
		//Iterate through Overlapped Actors
		for (auto Actor : OverlappedActors) {
			//If there is a chess piece
			if (Actor->IsA(AActorBase::StaticClass())) {
				AActorBase* ChessPiece = Cast<AActorBase>(Actor);
				if (ChessPiece != nullptr) {
					//Selectable grid if chess piece is enemy's since you can kill it
					if (ChessPiece->bIsWhite != this->bIsWhite) {
						AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
					}
				}
			}
		}
	}
	//Clears Arrays and destroys collisionchecker actor
	OverlappedActors.Empty();
	OverlappedComponents.Empty();
	CollisionChecker->Destroy();

	/*4. Setting Pawn's Diagonal left move*/
	if (bIsWhite) {
		SpawnLocation = FVector(GetActorLocation().X + 400.f, GetActorLocation().Y - 400.f, 0.f);
	}
	else {
		SpawnLocation = FVector(GetActorLocation().X - 400.f, GetActorLocation().Y + 400.f, 0.f);
	}
	//Spawns Collision checker
	CollisionChecker = GetWorld()->SpawnActor<ACollisionChecker>(SpawnLocation, FRotator::ZeroRotator);
	//Get overlapping actors by collision checker box
	CollisionChecker->GetOverlappingActors(OverlappedActors, TSubclassOf<AActor>());
	//Get overlapping components by collision checker box
	CollisionChecker->GetOverlappingComponents(OverlappedComponents);
	//Means there is a chess piece on the grid square of the chess board
	if (OverlappedActors.Num() > 1) {
		//Iterate through Overlapped Actors
		for (auto Actor : OverlappedActors) {
			//If there is a chess piece
			if (Actor->IsA(AActorBase::StaticClass())) {
				AActorBase* ChessPiece = Cast<AActorBase>(Actor);
				if (ChessPiece != nullptr) {
					//Selectable grid if chess piece is enemy's since you can kill it
					if (ChessPiece->bIsWhite != this->bIsWhite) {
						AddAndHighlight(SelectableGrids, DefaultMaterials, &OverlappedActors, &OverlappedComponents);
					}
				}
			}
		}
	}
	//Clears Arrays and destroys collisionchecker actor
	OverlappedActors.Empty();
	OverlappedComponents.Empty();
	CollisionChecker->Destroy();
}

void APawnPiece::AddAndHighlight(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials, TArray<AActor*>* OverlappedActors, TArray<UPrimitiveComponent*>* OverlappedComponents)
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