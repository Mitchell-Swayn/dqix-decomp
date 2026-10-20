#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_InitializeNetworkTaskContext(void);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcStepThreeScreen_StartPollingWhenReady(void);
// Original: arm9/ov031 @ 0x02231D08; symbol: func_ov031_02231d08; size: 0x40.
extern "C" void WfcStepThreeScreen_StartTaskWhenDisplaysIdle(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_InitializeNetworkTaskContext();
    WfcUtility_CreateBottomButtonsForDisplayMode(1);
    WfcUtility_SetMainLoopCallback(WfcStepThreeScreen_StartPollingWhenReady);
}
