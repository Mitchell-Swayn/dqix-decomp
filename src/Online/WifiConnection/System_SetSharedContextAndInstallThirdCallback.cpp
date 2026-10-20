#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void WfcUtility_BeginReadinessScreenExit(void);
// Original: arm9/ov031 @ 0x02232380; symbol: func_ov031_02232380; size: 0x20.
extern "C" void System_SetSharedContextAndInstallThirdCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_BeginReadinessScreenExit);
}
