#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_SelectInitialMenuAfterFade();
// Original: arm9/ov031 @ 0x02227F74; symbol: func_ov031_02227f74; size: 0x3C.
extern "C" void ConfigureDualContextEffects() {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 2, 0x14);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 2, 0x14);
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_SelectInitialMenuAfterFade);
}
