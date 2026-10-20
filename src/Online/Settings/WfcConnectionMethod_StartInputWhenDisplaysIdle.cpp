#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void ClearControlAndRegisterCallback33510UnlessValueMinusTwo(void);
// Original: arm9/ov031 @ 0x022334AC; symbol: func_ov031_022334ac; size: 0x3C.
extern "C" void WfcConnectionMethod_StartInputWhenDisplaysIdle(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(0);
    WfcUtility_SetMainLoopCallback(ClearControlAndRegisterCallback33510UnlessValueMinusTwo);
}
