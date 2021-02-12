#pragma once
#include "A_Node.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "A_Path.generated.h"


UCLASS()
class RASLECULETOILE_API UA_Path : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY() TArray<UA_Node*> nodeInPath;

public:
	UA_Path();
	TArray<UA_Node*> GetNodeInPath() { return nodeInPath; }


	void InitPath(UA_Node* _startNode, UA_Node* _endNode);
	TArray<UA_Node*> GetFinalPath(UA_Node* _start, UA_Node* _end);

};
