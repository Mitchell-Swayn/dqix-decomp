#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void WfcMultiScreen_BeginConditionalExitBrightnessTransition(void);
extern "C" void WfcUtility_SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0223130C; symbol: func_ov031_0223130c; size: 0x20.
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback((void *)WfcMultiScreen_BeginConditionalExitBrightnessTransition);
}
