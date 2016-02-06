// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "BasicCharacter.h"
#include "MainPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class GAMEOFGODS_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	bool moving = false;
	AMainPlayerController(const FObjectInitializer& ObjectInitializer);
	void ChooseTargetUnderMouseCursor();
	void MoveToMouseCursor();
	void SetNewMoveDestination();
	ABasicCharacter * clickedPawn = nullptr;

protected:
	// Begin PlayerController interface
	
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface
	// Input handlers
	void OnMoveForwardAxis(float axisValue);
	void OnMoveRightAxis(float axisValue);
	void OnMouseHorizontal(float axisValue);
	void OnMouseVertical(float axisValue);
	void OnZoomInAction();
	void OnZoomOutAction();
	void OnLookAroundStart();
	void OnLookAroundStop();
private:
	bool lookAroundEnabled = false;
	int32 mouseLockPositionX;
	int32 mouseLockPositionY;
	
	
};
