// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h" //Dump this class
#include "PatrolRouteLogic.h"
#include "Array.h"


EBTNodeResult::Type USelectNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//TODO Get patrol points via pawn
	UPatrolRouteLogic* patrolRouteLogic = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRouteLogic>();

	if (!ensure(patrolRouteLogic))
	{
		return EBTNodeResult::Failed;
	}

	//Warn against empty patrol routes
	TArray<AActor*> patrolPoints = patrolRouteLogic->GetPatrolPoints();

	if (patrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Empty Patrol Points array!!!"));//, patrolPoints->GetPawn()->GetHumanReadableName()));
	}

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