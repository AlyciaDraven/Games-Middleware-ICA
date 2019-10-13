 // Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MoveToPlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyAIController.h"
#include "IslandCharacter.h"
#include "EnemyCharacter.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAIController *CharPC = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	AIslandCharacter *Enemy = Cast<AIslandCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));

	if(Enemy)
	{
		CharPC->MoveToActor(Enemy, 5.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
		return EBTNodeResult::Failed;


	EBTNodeResult::Failed;
}


