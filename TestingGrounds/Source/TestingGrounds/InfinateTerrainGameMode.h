// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfinateTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfinateTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	AInfinateTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

private:

	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
		class UActorPool* NavMeshBoundsVolumePool;


};
