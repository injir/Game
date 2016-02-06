// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "BasicBuild.h"


// Sets default values
ABasicBuild::ABasicBuild()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicBuild::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicBuild::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

