#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void AdvanceToMode4WhenContextsClear(void);
// Original: arm9/ov031 @ 0x02229C84; symbol: func_ov031_02229c84; size: 0x34.
extern "C" void WfcUtility_FadeInMultiReturnNotice(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback((void*)AdvanceToMode4WhenContextsClear);
}
