#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallStateFiveCallbackWhenScreenZeroContextClear(void);
// Original: arm9/ov031 @ 0x02229A74; symbol: func_ov031_02229a74; size: 0x34.
extern "C" void Graphics_InitializeMainDisplayAndCallback(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_InstallStateFiveCallbackWhenScreenZeroContextClear);
}
