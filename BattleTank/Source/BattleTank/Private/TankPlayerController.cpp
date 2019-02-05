// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto tank = GetControlledTank();
	if (!tank) 	UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));

	UE_LOG(LogTemp, Warning, TEXT("playerController possesing %s"), *tank->GetName());


	//UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPLay"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


