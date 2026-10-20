#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallDeferredCallback();
// Original: arm9/ov031 @ 0x022327D4; symbol: System_InstallCallbackWhenContextsClear; size: 0x3C.
// When context byte 9 is clear on both screens, refreshes and installs the callback.
extern "C" void System_InstallCallbackWhenContextsClear() {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0)
        return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    WfcUtility_CreateBottomButtonsForDisplayMode(0);
    WfcUtility_SetMainLoopCallback(System_InstallDeferredCallback);
}
