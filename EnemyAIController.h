// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ISLAND_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(transient)
		class UBlackboardComponent *BlackboardComp;

	UPROPERTY(transient)
		class UBehaviorTreeComponent *BehaviorComp;

public:

	AEnemyAIController();

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID;
	
};
