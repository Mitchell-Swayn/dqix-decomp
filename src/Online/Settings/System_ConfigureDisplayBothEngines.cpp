#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_ArmAccessPointListAfterFadeIn();
// Original: arm9/ov031 @ 0x0222BA8C; symbol: func_ov031_0222ba8c; size: 0x54.
extern "C" void System_ConfigureDisplayBothEngines(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x1d, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x1d);
    WfcUtility_SetMainLoopCallback(WfcUtility_ArmAccessPointListAfterFadeIn);
}
