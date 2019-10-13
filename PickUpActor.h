// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"

UCLASS()
class ISLAND_API APickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	
};
