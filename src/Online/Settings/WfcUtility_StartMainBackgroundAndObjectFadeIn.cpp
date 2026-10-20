#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_InstallPollSelectCallbackWhenContextByte9IsZero(void);
// Original: arm9/ov031 @ 0x02233EE8; symbol: func_ov031_02233ee8; size: 0x34.
extern "C" void WfcUtility_StartMainBackgroundAndObjectFadeIn(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback((void*)System_InstallPollSelectCallbackWhenContextByte9IsZero);
}
