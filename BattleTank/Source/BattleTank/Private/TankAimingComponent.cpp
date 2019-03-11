// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{

	if (!ensure(Barrel)) { return; }


	FVector OUTLauchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OUTLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUTLauchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false, 0, 0
		, ESuggestProjVelocityTraceOption::DoNotTrace //Epic Bug: this needs to be here as DoNotTrace
		);
		
	if (bHaveAimSolution) 
	{
		auto AimDirection = OUTLauchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && Projectile_BP)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) {

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			Projectile_BP, 
			Barrel->GetSocketLocation("Projectile"), 
			Barrel->GetSocketRotation("Projectile"));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure (Barrel || Turret)) { return; }

	// Work-out difference between current rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Rotate(DeltaRotator.Yaw);

}

