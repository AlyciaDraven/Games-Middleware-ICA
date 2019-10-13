// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpActor.h"

// Sets default values
APickUpActor::APickUpActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void APickUpActor::BeginPlay()
{
	Super::BeginPlay();

}

void APickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
