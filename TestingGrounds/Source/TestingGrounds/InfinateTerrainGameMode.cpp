// Fill out your copyright notice in the Description page of Project Settings.

#include "InfinateTerrainGameMode.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfinateTerrainGameMode::AInfinateTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void AInfinateTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfinateTerrainGameMode::AddToPool(ANavMeshBoundsVolume* VolumeToAdd)
{
	//UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}
