#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRAdditionsBPLib.generated.h"


UCLASS()
class VRADDITIONS_API UVRAdditionsBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "VRAdditions")
		static void VRA_SendKeyInput(AActor* worldcontext, FKey KeyToSend, EInputEvent EventToSend, float depresed);
	
	UFUNCTION(BlueprintCallable, Category = "VRAdditions")
		static void VRA_PlayerControllerKeyInput(APlayerController* player, FKey KeyToSend, EInputEvent EventToSend, float InDelta, FInputDeviceId deviceid);
};