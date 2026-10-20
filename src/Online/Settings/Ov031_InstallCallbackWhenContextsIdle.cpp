#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned);
extern "C" void System_ClearAndRegisterSecondCallbackUnlessSharedByteMinusTwo();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02232188; symbol: func_ov031_02232188; size: 0x3C.
extern "C" ARM void Ov031_InstallCallbackWhenContextsIdle() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(1);
    WfcUtility_SetMainLoopCallback(System_ClearAndRegisterSecondCallbackUnlessSharedByteMinusTwo);
}
