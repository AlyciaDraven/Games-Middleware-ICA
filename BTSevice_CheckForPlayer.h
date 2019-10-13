// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTSevice_CheckForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ISLAND_API UBTSevice_CheckForPlayer : public UBTService
{
	GENERATED_BODY()
	
public:

	UBTSevice_CheckForPlayer();

	/** update next tick interval
	 * this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};
