// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOfGods.h"
#include "GlobalMapInterface.h"




// ToStringInterface
UGlobalMapInterface::UGlobalMapInterface(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

//This is required for compiling, would also let you know if somehow you called
//the base event/function rather than the over-rided version
void IGlobalMapInterface::showObjectInformation()
{
	
}