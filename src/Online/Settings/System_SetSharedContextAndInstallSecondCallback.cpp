#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void WfcUtility_BeginConnectionErrorFadeOut(void);
// Original: arm9/ov031 @ 0x0222E8F0; symbol: func_ov031_0222e8f0; size: 0x20.
extern "C" void System_SetSharedContextAndInstallSecondCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_BeginConnectionErrorFadeOut);
}
