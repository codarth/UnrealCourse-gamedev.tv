// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto tank = GetControlledTank();
	if (!tank) 	UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));

	UE_LOG(LogTemp, Warning, TEXT("AIController possesing %s"), *tank->GetName());


	//UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPLay"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
