#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallMainLoopCallbackUnlessSharedByteIsMinus2();
// Original: arm9/ov031 @ 0x02228EB8; symbol: func_ov031_02228eb8; size: 0x3C.
extern "C" void System_StartModeTwoIfBothContextsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(2);
    WfcUtility_SetMainLoopCallback(System_InstallMainLoopCallbackUnlessSharedByteIsMinus2);
}
