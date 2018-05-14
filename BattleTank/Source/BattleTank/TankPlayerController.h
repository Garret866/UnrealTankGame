// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
//forward declr:
class ATank;
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank * GetControlledTank() const;
	//start the tank moving the barrel and turret so the shot would hit where the crosshair intersects with the world
	void AimTowardsCrosshair();
	//return an out param, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const; 

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000; //10km is 1mil cm

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

};
