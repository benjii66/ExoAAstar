#include "MouvementTest.h"


UMouvementTest::UMouvementTest()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UMouvementTest::BeginPlay()
{
	Super::BeginPlay();
}


void UMouvementTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!test)
	{
		GetPathToTarget();
		test = true;
	}
	else
	{
		for (int i = 0; i < pathFinal->GetNodeInPath().Num(); i++)
			pathFinal->GetNodeInPath()[i]->PrintSth(GetWorld(), pathFinal->GetNodeInPath()[i]->GetPosition() + (FVector::UpVector * 300), FColor::Yellow);
	}
}


void UMouvementTest::GetPathToTarget()
{
	if (!target || !player) return;

	UActorComponent* _component = player->GetComponentByClass(pathFindClass);
	UA_PathFinder* _pathFinder = Cast<UA_PathFinder>(_component);

	if (!_pathFinder) return;
	pathFinal = _pathFinder->GetPathBetweenTwoActor(_pathFinder->GetNavGrind()->GetCloseNode(player->GetActorLocation()), _pathFinder->GetNavGrind()->GetCloseNode(target->GetActorLocation()));
	if (!pathFinal) return;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, FString::Printf(TEXT("Node Number : %d"), pathFinal->GetNodeInPath().Num()));
}

