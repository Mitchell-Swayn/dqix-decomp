#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetConnectionEventCallback(unsigned int value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Math_InitializeDivisionAndInverse(void);
extern "C" void WfcUtility_HandleMultiNoticeResult(void);
// Original: arm9/ov031 @ 0x02229860; symbol: func_ov031_02229860; size: 0x30.
extern "C" void Overlay_InitializeCallbacksWhenContextByteZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_SetConnectionEventCallback((unsigned int)WfcUtility_HandleMultiNoticeResult);
    WfcUtility_SetMainLoopCallback(Math_InitializeDivisionAndInverse);
}
