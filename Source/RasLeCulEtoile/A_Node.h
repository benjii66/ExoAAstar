#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "A_Node.generated.h"


UCLASS()
class RASLECULETOILE_API UA_Node : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(SimpleDisplay) FVector position;
	UPROPERTY() bool isNavigable;

	UPROPERTY() float g;
	UPROPERTY() float h;

	UPROPERTY(SimpleDisplay) UA_Node* predecessor;
	UPROPERTY(SimpleDisplay) TArray<UA_Node*> AllSuccessor;


public:

	UA_Node();
	UA_Node(float _x, float _y, float _z);

	float GetG() { return g; }
	float GetH() { return h; }
	float GetTotalWeight() { return g + h; }

	void SetG(float _newValue) { g = _newValue; }
	void SetH(float _newValue) { h = _newValue; }

	FVector GetPosition() { return position; }

	bool GetNavigable() { return isNavigable; }
	void SetNavigable(bool _status) { isNavigable = _status; }

	UA_Node* GetPredecessor() { return predecessor; }
	void SetPredecessor(UA_Node* _newPredecessor) { predecessor = _newPredecessor; }

	TArray<UA_Node*> GetSuccessor() { return  AllSuccessor; }

	void InitNode(float _x, float _y, float _z);
	void AddSuccessor(UA_Node* _newSuccessor);
	void ResetCost();


	void PrintPos(UWorld* _world, FVector _pos, FColor _color);
	void PrintSth(UWorld* _world, FVector _pos, FColor _color);
};
