#pragma once
#include "A_Path.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

UCLASS()
class RASLECULETOILE_API AGridManager : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnyWhere, Category = "Settings") int size = 5;
	UPROPERTY(EditAnyWhere, Category = "Settings") TSubclassOf<UObject> nodeClass;

	UPROPERTY(EditAnyWhere, Category = "GridNode") TArray<UA_Node*> allNodeInGrid;


protected:
	virtual void BeginPlay() override;

	void GenerateGrind();
	void GetSuccessors();

public:
	AGridManager();

	virtual void Tick(float DeltaTime) override;

	TArray<UA_Node*> GetGrind() { return allNodeInGrid; };

	void ResetGrindCost();

	UA_Node* GetCloseNode(FVector _pos);

};
