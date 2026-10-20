#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo();
// Original: arm9/ov031 @ 0x0222E82C; symbol: func_ov031_0222e82c; size: 0x3C.
extern "C" void System_InstallCallbackWhenBothContextBytesClear() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(4);
    WfcUtility_SetMainLoopCallback(System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo);
}
