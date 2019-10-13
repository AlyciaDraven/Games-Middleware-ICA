// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IslandCharacter.h"
#include "MedKit.generated.h"

UCLASS()
class ISLAND_API AMedKit : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMedKit();

public:

	UFUNCTION()
		void OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		AIslandCharacter* MyCharacter;
};