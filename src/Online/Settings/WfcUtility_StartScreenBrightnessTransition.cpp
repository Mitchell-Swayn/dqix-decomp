#include <globaldefs.h>
ARM
#pragma force_active on
struct BrightnessTransition { void* task; short frame; unsigned short duration; unsigned char mode,active; unsigned short padding; };
extern "C" {
// Original data: arm9/ov031 @ 0x022493a0; symbol: data_ov031_022493a0; transition endpoints occupy bytes 8 through 11.
extern const unsigned char WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x02290d34; symbol: data_ov031_02290d34; initially zero, two transition records.
extern BrightnessTransition* WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;
void ColorEffect_ConfigureBrightnessAdjust(unsigned,unsigned,int);
void WfcUtility_AdvanceScreenBrightnessTransition(void*,void*);
void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
}
// Original: arm9/ov031 @ 0x0223c078; symbol: func_ov031_0223c078; size: 0xd8.
// Starts a brightness task for an idle screen and records its mode, duration, and active flag.
extern "C" int WfcUtility_StartScreenBrightnessTransition(unsigned mode,int screen,unsigned planes,unsigned duration)
{
    signed char endpoints[4]={WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[8],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[9],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[10],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[11]};
    BrightnessTransition* state;
    if(screen==1) state=WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;
    else state=WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage+1;
    if(state->active) return 0;
    if(screen==1) ColorEffect_ConfigureBrightnessAdjust(0x04001050,planes,endpoints[mode]);
    else ColorEffect_ConfigureBrightnessAdjust(0x04000050,planes,endpoints[mode]);
    state->task=WfcUtility_CreateTaskWithBorrowedContext(1,WfcUtility_AdvanceScreenBrightnessTransition,state,200);
    state->frame=0;
    state->mode=mode;
    state->duration=duration;
    state->active=1;
    return 1;
}
#pragma force_active reset
