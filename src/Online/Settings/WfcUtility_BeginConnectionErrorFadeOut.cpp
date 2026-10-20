#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback(void);
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void Graphics_TransitionFromIdleDisplayContexts(void);
// Original: arm9/ov031 @ 0x0222E910; symbol: func_ov031_0222e910; size: 0x50.
extern "C" void WfcUtility_BeginConnectionErrorFadeOut(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    System_SetReadyAndScheduleWordCallback();
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback((void*)Graphics_TransitionFromIdleDisplayContexts);
}
