// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "MainPlayerController.h"
#include "BasicCharacter.h"
#include "GlobalMapSpectatorPawn.h"


AGlobalMapSpectatorPawn::AGlobalMapSpectatorPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for player capsule
	//GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction, except for the yaw axis
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Disable Jump and Crouch actions
	bAddDefaultMovementBindings = false;

	// Configure character movement
	/*GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;*/

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = false; // Rotate arm relative to character
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

										  // Move camera boom with character only on yaw rotation
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritYaw = true;

	// Enables camera lag - matter of taste
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bEnableCameraRotationLag = true;

	// Disable collisions
	GetCollisionComponent()->bGenerateOverlapEvents = false;
	GetCollisionComponent()->SetCollisionProfileName("NoCollision");

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}
void AGlobalMapSpectatorPawn::ChangeCameraArmLength(float changeValue)
{
	CameraBoom->TargetArmLength += changeValue * 100.0f; // Change 100.0f with zoom speed property
}

void AGlobalMapSpectatorPawn::RotateCameraArm(FRotator rotation)
{
	CameraBoom->AddRelativeRotation(rotation);
}

void AGlobalMapSpectatorPawn::MoveCharacterForward(float changeValue)
{
	AddMovementInput(GetActorForwardVector(), changeValue);
}

void AGlobalMapSpectatorPawn::MoveCharacterRight(float changeValue)
{
	AddMovementInput(GetActorRightVector(), changeValue);
}







//
//AGlobalMapSpectatorPawn::AGlobalMapSpectatorPawn() {
//
//}
//void AGlobalMapSpectatorPawn::BeginPlay()
//{
//	Super::BeginPlay();
//	ProssesClicked();
//	
//}
//
//void AGlobalMapSpectatorPawn::ProssesClicked() {
//	AMainPlayerController * playerController = Cast<AMainPlayerController>(GetController());
//	if (playerController != nullptr) {
//		
//		playerController->GetMousePosition(LocationX, LocationY);
//		FVector2D MousePosition(LocationX, LocationY);
//		
//		const bool bTraceComplex = false;
//		playerController->CastToPlayerController()->GetHitResultUnderCursor(ECC_Pawn, false, HitResult);
//		//playerController->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, bTraceComplex, HitResult);
//		if (HitResult.bBlockingHit) {
//			if (HitResult.Actor != NULL) {
//				ClickedPawn = Cast<ABasicCharacter>(HitResult.GetActor());
//				if (ClickedPawn != nullptr){
//					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString(ClickedPawn->GetName()));
//					float a = 400;
//					FVector scale(a,a,0.0);
//					//ClickedPawn->AddMovementInput(scale, 5.0);
//					FVector vec = FMath::InterpEaseIn(ClickedPawn->GetActorLocation(), ClickedPawn->GetActorLocation() + FVector(100, 100, 100), 1,10);
//					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, vec.ToString());
//					//AMainPlayerController aiChar = Cast<AIController>();
//					//ClickedPawn->SetActorLocation(vec);
//					ClickedPawn->MoveCharacterTo(FVector(-100,-200, 0));
//					//ClickedPawn->CharacterMovement;
//					//ClickedPawn->AIControllerClass->GetName();
//					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString(ClickedPawn->AIControllerClass->GetName()));
//					//ClickedPawn->execAddMovementInput();
//					//ClickedPawn->AddMovementInput(vec, 1.0);
//					//ClickedPawn->MoveTo(vec);
//				}
//			}
//		}
//		//if (playerController->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, bTraceComplex, HitResult) == true)
//		//{
//		//	// If the actor we intersected with is a controller posses it  
//		//	ClickedPawn = Cast<ABasicCharacter>(HitResult.GetActor());
//		//	Hit = true;
//		//	if (ClickedPawn != nullptr)
//		//	{
//		//		// Unposses ourselves  
//		//		playerController->UnPossess();
//		//		// Posses the controller we clicked on  
//		//		playerController->Possess(ClickedPawn);
//		//		
//		//		
//		//	}
//		//}
//		//else {
//		//	Hit = false;
//		//}
//		//
//		//if (GEngine)
//		//{
//		//	if (ClickedPawn != nullptr) {
//		//		//FString name = (FString)ClickedPawn->GetName();
//		//		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString(ClickedPawn->GetName()));
//
//		//	}
//		//	else {
//		//		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString(HitResult.GetActor()->GetName()));
//		//	}
//		//}
//	}
//	
//	
//}
//

