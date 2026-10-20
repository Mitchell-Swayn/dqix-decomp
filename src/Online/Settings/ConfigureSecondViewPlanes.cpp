#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_WaitForOptionsMenuFade();
// Original: arm9/ov031 @ 0x022292C0; symbol: func_ov031_022292c0; size: 0x54.
extern "C" void ConfigureSecondViewPlanes() {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x14, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x14);
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_WaitForOptionsMenuFade);
}
