// Copyright Cody Crawford 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	float Reach = 100.f;
		
	class UPhysicsHandleComponent* PhysicsHandle = nullptr;

	class UInputComponent* InputComponent = nullptr;


	void Grab();
	void Release();

	void FindPhysicsHandleComponent();

	void SetupInputComponent();

	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Return current start of reach line
	FVector GetReachLineStart() const;

	// Return current end of reach line
	FVector GetReachLineEnd() const;
};
