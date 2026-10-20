#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_ScheduleSetupPollingTask();
// Original: arm9/ov031 @ 0x0222B010; symbol: func_ov031_0222b010; size: 0x3C.
extern "C" void WfcUtility_FinishSetupPromptFadeIn(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(1);
    WfcUtility_SetMainLoopCallback(WfcUtility_ScheduleSetupPollingTask);
}
