// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	auto possessedTank = GetControlledTank();
	//check proper player tank possession
	if (possessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller possesing %s"), *possessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("pplayer controller not possesing tank ?"));
	}
	//activate ticking
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; //Out parameter
	//if (GetSightRayHitLocation(HitLocation))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("No Hit"));
	//}
	GetSightRayHitLocation(HitLocation);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//this function raycasts from playercontroller.getcamera.center
	//checks if it hit something on the visibility channel
	//returns true and changes the & param with hit point if true
	//else false


	//calc dot location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//get the direction we are aiming at with the crosshair, and the location of the aimer
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//shoot a line trace along the lookdirection.
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString())
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector AimLocation; //discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, AimLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	//returns where in the world we hit, reutnrs fvector(0) if not hit anything.

	FHitResult HitResult;
	FCollisionQueryParams ColQueryParams(FName(TEXT("AimingTrace")), false);
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, StartLocation + LookDirection*LineTraceRange, ECC_Visibility, ColQueryParams);
	HitLocation = HitResult.ImpactPoint;

}


