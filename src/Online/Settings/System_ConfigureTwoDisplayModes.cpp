#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void MainLoop_InitializeWhenContextReady();
// Original: arm9/ov031 @ 0x0222B564; symbol: func_ov031_0222b564; size: 0x3C.
extern "C" void System_ConfigureTwoDisplayModes(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(MainLoop_InitializeWhenContextReady);
}
