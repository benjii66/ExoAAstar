#include "GridManager.h"
#include <DrawDebugHelpers.h>

AGridManager::AGridManager()
{
    PrimaryActorTick.bCanEverTick = true;
    allNodeInGrid = TArray<UA_Node*>();
}


void AGridManager::BeginPlay()
{
    Super::BeginPlay();
    GenerateGrind();
}


void AGridManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    for (int i = 0; i < allNodeInGrid.Num(); i++)
        allNodeInGrid[i]->PrintPos(GetWorld(), allNodeInGrid[i]->GetPosition(), FColor::Emerald);

}


void AGridManager::GenerateGrind()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            UA_Node* _node = NewObject<UA_Node>();
            _node->InitNode(i * 200, j * 200, GetActorLocation().Z);
            allNodeInGrid.Add(_node);
        }
    }
    GetSuccessors();
}

void AGridManager::GetSuccessors()
{
    for (int i = 0; i < size * size; i++)
    {
        bool _canRight = i % size != (size - 1);
        bool _canLeft = i % size != 0;
        bool _canTop = i >= size;
        bool _canDown = i < (size* size) - size;

        if (_canRight) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i + 1]);
        if (_canLeft) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i - 1]);
        if (_canTop)
        {
            allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i - size]);
            if (_canRight) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i + 1 - size]);
            if (_canLeft) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i - 1 - size]);
        }
        if (_canDown)
        {
            allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i + size]);
            if (_canRight) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i + 1 + size]);
            if (_canLeft) allNodeInGrid[i]->AddSuccessor(allNodeInGrid[i - 1 + size]);
        }
    }
}

void AGridManager::ResetGrindCost()
{
    for (int i = 0; i < allNodeInGrid.Num(); i++)
        allNodeInGrid[i]->ResetCost();

}

UA_Node* AGridManager::GetCloseNode(FVector _pos)
{
    UA_Node* _node = nullptr;
    float _distance = std::numeric_limits<float>::max();;

    for (int i = 0; i < allNodeInGrid.Num(); i++)
    {
        float _tmpDistance = FVector::Dist(_pos, allNodeInGrid[i]->GetPosition());
        if (_tmpDistance < _distance)
        {
            _distance = _tmpDistance;
            _node = allNodeInGrid[i];
        }
    }
    return _node;
}
