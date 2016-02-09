// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "BasicCharacter.h"


// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	calculateStartStats();
	calculateHealth();

}
void ABasicCharacter::showObjectInformation() {
	FString msg = " strength:" + FString::FromInt(strength) + ", agility:" + FString::FromInt(agility) + ", intelligence:" +
		FString::FromInt(intelligence);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow,msg);
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ABasicCharacter::calculateStartStats() {
	int32 stats = StatsPoint;
	int32 randomStrength = int32((rand() % stats) + 1);
	stats = stats - randomStrength;
	int32 randomAgility = int32((rand() % stats) + 1);
	int32 randomIntelegence = int32(stats - randomAgility);
	strength = randomStrength;
	agility = randomAgility;
	intelligence = randomIntelegence;
}
void ABasicCharacter::calculateHealth() {
	health = (strength * 13) + 100;
}