// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"


EBTNodeResult::Type USelectNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//TODO Protect against empty patrol routes

	//TODO Get patrol points via pawn
	AAIController* ownerAI = OwnerComp.GetAIOwner();
	APawn* ownerPawn = ownerAI->GetPawn();
	APatrollingGuard* guardAI = Cast<APatrollingGuard>(ownerPawn);
	TArray<AActor*> patrolPoints = guardAI->PatrolPoints;

	//TODO Set next waypoint
	UBlackboardComponent* blackboardComp = OwnerComp.GetBlackboardComponent();
	int32 index = blackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	blackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, patrolPoints[index]); 

	//TODO Cycle the index
	auto nextIndex = (index + 1) % patrolPoints.Num();
	blackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, nextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("AI Execute task in C++"));
	//UE_LOG(LogTemp, Warning, TEXT("Index value = %i"), Index);
	return EBTNodeResult::Succeeded;
}