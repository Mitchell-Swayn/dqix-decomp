#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_ResetDisplayAndInstallStartupCallback();
// Original: arm9/ov031 @ 0x02231AB0; symbol: func_ov031_02231ab0; size: 0x3C.
extern "C" void ConfigureThirdContextEffects() {
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback((void*)System_ResetDisplayAndInstallStartupCallback);
}
