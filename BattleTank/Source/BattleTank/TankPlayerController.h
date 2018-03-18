// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPlayerControllerPRE.h"
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
	ATank* GetControlledTank() const;
	//start the tank moving the barrel so the shot would hit where the crosshair intersects with the world
	void AimTowardsCrosshair();
	//return an out param, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const; 

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000; //10km is 1mil cm
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

};
