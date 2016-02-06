// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "BasicBuild.h"
#include "BasicCity.h"



// Sets default values
ABasicCity::ABasicCity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ABasicCity::showObjectInformation() {
	/*for (int32 i; i < cityBuilds.Num(); i++) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, cityBuilds[i]->name);
		
	}*/
	/*for (auto Iter(cityBuilds.CreateIterator()); Iter; Iter++) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, (*Iter)->name);
	}*/
	
	
}
// Called when the game starts or when spawned
void ABasicCity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCity::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

