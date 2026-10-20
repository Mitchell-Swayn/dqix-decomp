#include <globaldefs.h>
ARM

extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallCallbackWhenSelectedContextByte9Zero(void);

// Original: arm9/ov031 @ 0x02229EF0; symbol: func_ov031_02229ef0; size: 0x54.
extern "C" void System_ConfigureDualDisplayPlanes(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenSelectedContextByte9Zero);
}
