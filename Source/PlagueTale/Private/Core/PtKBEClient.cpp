// Fill out your copyright notice in the Description page of Project Settings.


#include "PtKBEClient.h"
#include "Engine/KBEMain.h"

// Sets default values
APtKBEClient::APtKBEClient()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootScene");

	KBEMain = CreateDefaultSubobject<UKBEMain>("KBEMain");

}



