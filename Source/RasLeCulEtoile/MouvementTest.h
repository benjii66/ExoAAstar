#pragma once
#include "A_PathFinder.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MouvementTest.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RASLECULETOILE_API UMouvementTest : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere) AActor* target;
	UPROPERTY(EditAnywhere) AActor* player;
	UPROPERTY(EditAnyWhere) TSubclassOf<UActorComponent> pathFindClass;
	UPROPERTY(EditAnyWhere) bool test = false;

	UPROPERTY() UA_Path* pathFinal;

protected:
	virtual void BeginPlay() override;

public:
	UMouvementTest();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetPathToTarget();
};
