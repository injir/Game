// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "GlobalMapInterface.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class  UGlobalMapInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
	/*void doSomthing();
	void showObjectInformation();*/
};
class IGlobalMapInterface 
{
	GENERATED_IINTERFACE_BODY() 
	virtual void showObjectInformation();

};