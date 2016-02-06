// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GlobalMapInterface.h"
#include "BasicCharacter.generated.h"


UCLASS()
class GAMEOFGODS_API ABasicCharacter : public ACharacter, public IGlobalMapInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter();
	virtual void BeginPlay() override;
	FVector targetPoint;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	virtual void showObjectInformation() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
protected:
	float health;
	float experience;
	int32 strength;
	int32 agility;
	int32 intelligence;
	int32 StatsPoint = 30;
	void calculateStartStats();
	void calculateHealth();


	
	
};
