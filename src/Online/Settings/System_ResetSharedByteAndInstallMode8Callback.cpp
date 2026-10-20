#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void WfcUtility_BeginChoiceScreenFadeOut(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222A038; symbol: func_ov031_0222a038; size: 0x20.
extern "C" void System_ResetSharedByteAndInstallMode8Callback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_BeginChoiceScreenFadeOut);
}
