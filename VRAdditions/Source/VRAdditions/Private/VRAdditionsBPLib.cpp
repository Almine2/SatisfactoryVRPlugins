#include "VRAdditionsBPLib.h"
#include <Module/GameInstanceModule.h>


void UVRAdditionsBPLib::VRA_SendKeyInput(AActor* worldcontext, FKey KeyToSend, EInputEvent EventToSend, float depresed)
{
  //https://www.reddit.com/r/unrealengine/comments/dwjs1b/can_i_simulate_a_key_press_event_in_blueprint/
  UGameInstance* GameInst = worldcontext->GetWorld()->GetGameInstance();
  UGameViewportClient* ViewportClient = GameInst->GetGameViewportClient();
  FViewport* Viewport = ViewportClient->Viewport;

  int32 ControllerId = 0; // or whatever controller id, could be a function param
  FInputKeyEventArgs Args = FInputKeyEventArgs(
    Viewport,
    ControllerId,
    KeyToSend,
    EventToSend,
    depresed,false);

  ViewportClient->InputKey(Args);
}

void UVRAdditionsBPLib::VRA_PlayerControllerKeyInput(APlayerController* player, FKey KeyToSend, EInputEvent EventToSend, float InDelta, FInputDeviceId deviceid)
{
  if (player != nullptr) {
    FInputKeyParams Args = FInputKeyParams(
      KeyToSend,
      EventToSend,
      InDelta, false,deviceid);
    player->InputKey(Args);
  }
}
