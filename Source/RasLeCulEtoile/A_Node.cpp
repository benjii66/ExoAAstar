#include "A_Node.h"
#include <DrawDebugHelpers.h>


UA_Node::UA_Node()
{
	position = FVector(0, 0, 0);
	isNavigable = true;

	predecessor = nullptr;
	AllSuccessor = TArray<UA_Node*>();

	g = std::numeric_limits<float>::max();
	h = std::numeric_limits<float>::max();
}

UA_Node::UA_Node(float _x, float _y, float _z)
{
	position = FVector(_x, _y, _z);
	isNavigable = true;

	predecessor = nullptr;
	AllSuccessor = TArray<UA_Node*>();

	g = 10000;
	h = 10000;
}

void UA_Node::InitNode(float _x, float _y, float _z)
{
	position = FVector(_x, _y, _z);
	isNavigable = true;

	predecessor = nullptr;
	AllSuccessor = TArray<UA_Node*>();

	g = std::numeric_limits<float>::max();
	h = std::numeric_limits<float>::max();
}

void UA_Node::AddSuccessor(UA_Node* _newSuccessor)
{
	if (!_newSuccessor) return;
	AllSuccessor.Add(_newSuccessor);
}

void UA_Node::ResetCost()
{
	g = std::numeric_limits<float>::max();
	h = std::numeric_limits<float>::max();
}



void UA_Node::PrintPos(UWorld* _world, FVector _pos, FColor _color)
{
	DrawDebugBox(_world, _pos, 50 * FVector::OneVector, _color);
	for (int i = 0; i < AllSuccessor.Num(); i++)
		DrawDebugLine(_world, position, AllSuccessor[i]->position, _color);
}
void UA_Node::PrintSth(UWorld* _world, FVector _pos, FColor _color)
{
	DrawDebugSphere(_world, _pos, 50,32, _color);

}
