#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_ArmResponsePromptInput(void);
// Original: arm9/ov031 @ 0x0222A480; symbol: func_ov031_0222a480; size: 0x3C.
extern "C" void WfcUtility_FinishResponsePromptFadeIn(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(3);
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_ArmResponsePromptInput);
}
