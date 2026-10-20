#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned mode);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_EnableMultiScreenInput(void);
// Original: arm9/ov031 @ 0x022286B8; symbol: func_ov031_022286b8; size: 0x3C.
extern "C" void WfcUtility_WaitForMultiScreenFade(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(3);
    WfcUtility_SetMainLoopCallback(WfcUtility_EnableMultiScreenInput);
}
