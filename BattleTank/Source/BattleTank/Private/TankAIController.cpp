// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank)) {
		// Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// AimToward the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire at player
		ControlledTank->Fire(); //TODO limit Fire rate
	}
}

//ATank* ATankAIController::GetControlledTank() const
//{
//	return Cast<ATank>(GetPawn());
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//
//	if (!PlayerPawn) { return nullptr;	}
//
//	return Cast<ATank>(PlayerPawn);
//}
