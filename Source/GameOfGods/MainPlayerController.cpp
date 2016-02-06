// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "GlobalMapSpectatorPawn.h"
#include "MainPlayerController.h"
#include "BasicCharacter.h"
#include "CustomAIController.h"
AMainPlayerController::AMainPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShowMouseCursor = true;
}

void AMainPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (clickedPawn != nullptr ) {
		SetNewMoveDestination();
	}

}

//void AMainPlayerController::SetupInputComponent()
//{
//	// set up gameplay key bindings
//	Super::SetupInputComponent();
//}

void  AMainPlayerController::SetupInputComponent()
{
	// Set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AMainPlayerController::OnMoveForwardAxis);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayerController::OnMoveRightAxis);
	InputComponent->BindAxis("MouseHorizontal", this, &AMainPlayerController::OnMouseHorizontal);
	InputComponent->BindAxis("MouseVertical", this, &AMainPlayerController::OnMouseVertical);
	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &AMainPlayerController::OnZoomInAction);
	InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &AMainPlayerController::OnZoomOutAction);
	InputComponent->BindAction("LookAround", EInputEvent::IE_Pressed, this, &AMainPlayerController::OnLookAroundStart);
	InputComponent->BindAction("LookAround", EInputEvent::IE_Released, this, &AMainPlayerController::OnLookAroundStop);
	InputComponent->BindAction("LeftClick", EInputEvent::IE_Released, this, &AMainPlayerController::ChooseTargetUnderMouseCursor);
	InputComponent->BindAction("RightClick", EInputEvent::IE_Released, this, &AMainPlayerController::MoveToMouseCursor);
}
void AMainPlayerController::ChooseTargetUnderMouseCursor()
{
	/*if (clickedPawn != nullptr) {
		delete clickedPawn;
		clickedPawn = nullptr;
	}*/
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Pawn, false, Hit);
	if (Hit.bBlockingHit) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, Hit.GetActor()->GetName());
		IGlobalMapInterface * mapObj = Cast<IGlobalMapInterface>(Hit.GetActor());
		clickedPawn = Cast<ABasicCharacter>(Hit.GetActor());
		if (mapObj != nullptr) {
			mapObj->showObjectInformation();
		}

		
		
		/*if (clickedPawn == nullptr) {
			Cast<IGlobalMapInterface>(Hit.GetActor())->showObjectInformation();
		}*/
	}
	
}

void AMainPlayerController::MoveToMouseCursor() {
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit)
	{
		/*if (targetPoint != nullptr) {
			delete targetPoint;
		}*/
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, Hit.ImpactPoint.ToString());
		if (clickedPawn != nullptr) {
			clickedPawn->targetPoint = Hit.ImpactPoint;
		}
		
	}
}
void AMainPlayerController::SetNewMoveDestination()
{
	if (clickedPawn != nullptr ) {
		
		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, clickedPawn->GetController()->GetName());
		ACustomAIController *ai = Cast<ACustomAIController>(clickedPawn->GetController());
		
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, clickedPawn->targetPoint.ToString());
			UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
			float const Distance = FVector::Dist(clickedPawn->targetPoint, clickedPawn->GetActorLocation());
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, NavSys->GetName());
			// We need to issue move command only if far enough in order for walk animation to play correctly
			ai->MoveToLocation(clickedPawn->targetPoint);
						
	}
}



void AMainPlayerController::OnMoveForwardAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AGlobalMapSpectatorPawn* character = Cast<AGlobalMapSpectatorPawn>(Pawn);
	if (character)
	{
		character->MoveCharacterForward(axisValue);
	}
}

void AMainPlayerController::OnMoveRightAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AGlobalMapSpectatorPawn* character = Cast<AGlobalMapSpectatorPawn>(Pawn);
	if (character)
	{
		character->MoveCharacterRight(axisValue);
	}
}

void AMainPlayerController::OnMouseHorizontal(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		Pawn->AddControllerYawInput(axisValue);
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}
void AMainPlayerController::OnMouseVertical(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		AGlobalMapSpectatorPawn* character = Cast<AGlobalMapSpectatorPawn>(Pawn);
		if (character)
		{
			character->RotateCameraArm(FRotator(axisValue, 0.0f, 0.0f));
		}
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}

void AMainPlayerController::OnZoomInAction()
{
	APawn* const Pawn = GetPawn();
	AGlobalMapSpectatorPawn* character = Cast<AGlobalMapSpectatorPawn>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(-1.0f);
	}
}

void AMainPlayerController::OnZoomOutAction()
{
	APawn* const Pawn = GetPawn();
	AGlobalMapSpectatorPawn* character = Cast<AGlobalMapSpectatorPawn>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(1.0f);
	}
}

void AMainPlayerController::OnLookAroundStart()
{
	//Lock mouse cursor
	lookAroundEnabled = true;
	bShowMouseCursor = false;
	mouseLockPositionX = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseX();
	mouseLockPositionY = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseY();
}

void AMainPlayerController::OnLookAroundStop()
{
	//Unlock mouse cursor
	lookAroundEnabled = false;
	bShowMouseCursor = true;
}