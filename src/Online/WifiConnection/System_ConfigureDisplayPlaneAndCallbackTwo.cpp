#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallAlternateCallbackWhenSelectedContextByte9Zero();
// Original: arm9/ov031 @ 0x02234A08; symbol: func_ov031_02234a08; size: 0x34.
extern "C" void System_ConfigureDisplayPlaneAndCallbackTwo(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_InstallAlternateCallbackWhenSelectedContextByte9Zero);
}
