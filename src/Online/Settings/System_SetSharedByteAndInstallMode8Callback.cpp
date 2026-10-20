#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void WfcStepThreeScreen_BeginConditionalExitBrightnessTransition(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02231DF8; symbol: func_ov031_02231df8; size: 0x20.
extern "C" void System_SetSharedByteAndInstallMode8Callback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcStepThreeScreen_BeginConditionalExitBrightnessTransition);
}
