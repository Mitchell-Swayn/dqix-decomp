#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_EnableOptionsMenuInput(void);
// Original: arm9/ov031 @ 0x02229314; symbol: func_ov031_02229314; size: 0x3C.
extern "C" void WfcUtility_WaitForOptionsMenuFade(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(0);
    WfcUtility_SetMainLoopCallback(WfcUtility_EnableOptionsMenuInput);
}
