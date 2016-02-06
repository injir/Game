// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GlobalMapInterface.h"
#include "BasicBuild.h"
#include "BasicCity.generated.h"


UCLASS()
class GAMEOFGODS_API ABasicCity : public AActor, public IGlobalMapInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicCity();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void showObjectInformation() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<ABasicBuild*> cityBuilds;
	
	
};
