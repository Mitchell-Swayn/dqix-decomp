#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void WfcUtility_FadeOutSystemInformationScreen(void);
// Original: arm9/ov031 @ 0x02228F7C; symbol: func_ov031_02228f7c; size: 0x20.
extern "C" void System_SetSharedContextAndCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_FadeOutSystemInformationScreen);
}
