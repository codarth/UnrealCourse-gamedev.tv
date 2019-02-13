// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		//UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("AIController (Tank: %s) found player: %s"), *GetControlledTank()->GetName(), *PlayerTank->GetName());
	}

	//UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPLay"));
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetPlayerTank()) {
		//TODO Move Towards the player

		// AimToward the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire at player
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr;	}

	return Cast<ATank>(PlayerPawn);
}
