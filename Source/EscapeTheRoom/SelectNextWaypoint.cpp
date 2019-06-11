// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USelectNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//UE_LOG(LogTemp, Warning, TEXT("AI Execute task in C++"));
	UE_LOG(LogTemp, Warning, TEXT("Index value = %i"), Index);
	return EBTNodeResult::Succeeded;
}