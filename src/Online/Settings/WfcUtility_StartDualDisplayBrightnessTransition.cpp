#include <globaldefs.h>
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Ov031_InstallCallbackWhenContextsIdle();
// Original: arm9/ov031 @ 0x02232134; symbol: func_ov031_02232134; size: 0x54.
extern "C" void WfcUtility_StartDualDisplayBrightnessTransition(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(Ov031_InstallCallbackWhenContextsIdle);
}
