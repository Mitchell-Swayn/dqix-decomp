#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_SetFallbackCallbackWhenScreenZeroContextByte9IsClear(void);
// Original: arm9/ov031 @ 0x02231A44; symbol: func_ov031_02231a44; size: 0x34.
extern "C" void WfcUtility_StartMainDisplayCounterScreenTransition(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_SetFallbackCallbackWhenScreenZeroContextByte9IsClear);
}
