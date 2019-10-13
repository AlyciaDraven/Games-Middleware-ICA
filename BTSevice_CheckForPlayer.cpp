// Fill out your copyright notice in the Description page of Project Settings.

#include "BTSevice_CheckForPlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "IslandCharacter.h"
#include "EnemyAIController.h"
#include "EnemyCharacter.h"

UBTSevice_CheckForPlayer::UBTSevice_CheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UBTSevice_CheckForPlayer::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	AEnemyAIController *EnemyPC = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (EnemyPC)
	{
		AIslandCharacter *Enemy = Cast<AIslandCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (Enemy)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID, Enemy);
		}
	}
}
