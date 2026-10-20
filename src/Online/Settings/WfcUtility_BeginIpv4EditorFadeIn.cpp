#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void InitializeIdleSelectionAndSetMainLoopCallback(void);
// Original: arm9/ov031 @ 0x0222D950; symbol: func_ov031_0222d950; size: 0x54.
extern "C" void WfcUtility_BeginIpv4EditorFadeIn(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback((void*)InitializeIdleSelectionAndSetMainLoopCallback);
}
