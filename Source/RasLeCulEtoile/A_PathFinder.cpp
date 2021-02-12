#include "A_PathFinder.h"



UA_PathFinder::UA_PathFinder()
{
	PrimaryComponentTick.bCanEverTick = true;
	pathToFollow = nullptr;
}


void UA_PathFinder::BeginPlay()
{
	Super::BeginPlay();

}

void UA_PathFinder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}



UA_Path* UA_PathFinder::GetPathBetweenTwoActor(UA_Node* _startNode, UA_Node* _endNode)
{
	grid->ResetGrindCost();

	TArray<UA_Node*> _openList = TArray<UA_Node*>();
	_startNode->SetG(0);
	_openList.Add(_startNode);

	while (_openList.Num() != 0)
	{
		UA_Node* _current = _openList[0];
		if (_current == _endNode)
		{
			UA_Path* _path = NewObject<UA_Path>();
			_path->InitPath(_startNode, _endNode);
			return _path;
		}
		_openList.Remove(_current);

		for (int i = 0; i < _current->GetSuccessor().Num(); i++)
		{
			UA_Node* _succesor = _current->GetSuccessor()[i];
			float _g = _current->GetG() + FVector::Dist(_current->GetPosition(), _current->GetSuccessor()[i]->GetPosition());

			if (_g < _current->GetSuccessor()[i]->GetG())
			{
				_succesor->SetPredecessor(_current);
				_succesor->SetG(_g);
				_succesor->SetH(FVector::Dist(_succesor->GetPosition(), _endNode->GetPosition()));

				if (!_openList.Contains(_succesor) && _succesor->GetNavigable())
				{
					_openList.Add(_succesor);
				}

			}

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("No Pathfind")));
	return nullptr;
}
