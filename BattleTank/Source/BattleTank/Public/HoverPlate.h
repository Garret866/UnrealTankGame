// Copyright NobodyEntertainment inc

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "HoverPlate.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UHoverPlate : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//maximum distance in cm from the ground - after this it wont apply force anymore.
	UPROPERTY(Category = "Setup", EditDefaultsOnly)
		float MaxHeight = 100;
	//The force that is applied from the hoverplate when its 0cm from the ground - it multiplies weight of tank by this;
	UPROPERTY(Category = "Setup", EditDefaultsOnly)
		float MaxforceMultiplier = 2;
	
	//from these we can make a mth function - f(x) = -MaxforceMultiplier/MaxHeight + MaxforceMultiplier
	//f(x) = force multiplier, x = distance from ground.
	
	//this function traces to the first surface it reaches using Start Vector. Trace Length is MaxHeight
	//&Distance is the distance it returns. bool if there is a surface
	bool GetDistanceToSurface(float &Distance, FVector* StartLocation);

	//pushes the tank upwards at the PlateMiddle
	void ApplyUpForce(float Force);

	FVector PlateMiddle;
	FVector UpForceDirection;
	
};
