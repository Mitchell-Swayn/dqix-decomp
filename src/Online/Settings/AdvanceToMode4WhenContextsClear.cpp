#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallAlternateMainLoopCallbackUnlessSharedByteIsMinus2();
// Original: arm9/ov031 @ 0x02229CB8; symbol: AdvanceToMode4WhenContextsClear; size: 0x3C.
// When context byte 9 is clear for both selectors 1 and 0, selects mode 4 and installs the next callback.
extern "C" void AdvanceToMode4WhenContextsClear() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(4);
    WfcUtility_SetMainLoopCallback(System_InstallAlternateMainLoopCallbackUnlessSharedByteIsMinus2);
}
