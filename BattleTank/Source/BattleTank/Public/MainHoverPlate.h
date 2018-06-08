// Copyright NobodyEntertainment inc

#pragma once

#include "CoreMinimal.h"
#include "HoverPlate.h"
#include "MainHoverPlate.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UMainHoverPlate : public UHoverPlate
{
	GENERATED_BODY()
	
public:
	//Throttle linearly. e.g forward,backward, side.
	void ApplyLinearForce(float ForwardThrow, float RightThrow);
	
	FVector ForwardForceDirection;
	FVector RightForceDirection;
};
