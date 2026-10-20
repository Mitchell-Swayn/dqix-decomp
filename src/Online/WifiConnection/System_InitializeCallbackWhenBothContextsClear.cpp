#include <globaldefs.h>
ARM

extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ClearControlAndInstallCallbackUnlessSentinel(void);

// Original: arm9/ov031 @ 0x0223466C; symbol: func_ov031_0223466c; size: 0x3C.
extern "C" void System_InitializeCallbackWhenBothContextsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) {
        return;
    }
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) {
        return;
    }
    WfcUtility_CreateBottomButtonsForDisplayMode(6);
    WfcUtility_SetMainLoopCallback(System_ClearControlAndInstallCallbackUnlessSentinel);
}
