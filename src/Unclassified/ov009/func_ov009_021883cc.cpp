#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include <System/ColorEffects.h>
ARM
struct FadeState { char unknown0[0xc58]; signed char phase; unsigned char step; };
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(void*,int);
extern "C" void func_ov009_021855dc(FadeState*,int);
// Original: arm9/ov009 @ 0x021883CC; symbol: func_ov009_021883cc; size: 0x88.
extern "C" void func_ov009_021883cc(FadeState* state) {
 GameResources* controller=GameState_ReadPResources(GameState::GetInstance());
 if(state->step==0) {SetBrightness(controller,-16,15);state->step++;return;}
 if(state->step!=1)return;if(IsBrightnessTransitionActive(controller)!=0)return;
 Object_ResetSelectionAndApplyConfiguredMode((char*)state+0x1f8,1);Object_ResetSelectionAndApplyConfiguredMode((char*)state+0x2b4,1);
 ColorEffect_ConfigureBrightnessAdjust(0x04001050,1,0);func_ov009_021855dc(state,12);
}
