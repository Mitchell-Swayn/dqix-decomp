#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include <System/ColorEffects.h>
ARM
struct FadeState { char unknown0[0xc58]; signed char phase; unsigned char step; };
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void Window_PopCanvasesAndResetSelection(void*,int);
extern "C" void CharacterCreation_EnterPhaseAndMarkScreenDirty(FadeState*,int);
// Original: arm9/ov009 @ 0x021883CC; symbol: func_ov009_021883cc; size: 0x88.
extern "C" void CharacterCreation_UpdateExitFade(FadeState* state) {
 GameResources* controller=GameState_ReadPResources(GameState::GetInstance());
 if(state->step==0) {SetBrightness(controller,-16,15);state->step++;return;}
 if(state->step!=1)return;if(IsBrightnessTransitionActive(controller)!=0)return;
 Window_PopCanvasesAndResetSelection((char*)state+0x1f8,1);Window_PopCanvasesAndResetSelection((char*)state+0x2b4,1);
 ColorEffect_ConfigureBrightnessAdjust(0x04001050,1,0);CharacterCreation_EnterPhaseAndMarkScreenDirty(state,12);
}
