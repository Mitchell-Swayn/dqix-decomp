#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_EnableMultiNoticeCompletionInput(void);
// Original: arm9/ov031 @ 0x02229AA8; symbol: System_InstallStateFiveCallbackWhenScreenZeroContextClear; size: 0x2C.
// When screen zero context byte 9 is clear, selects state 5 and installs its callback.
extern "C" void System_InstallStateFiveCallbackWhenScreenZeroContextClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0) {
        WfcUtility_CreateBottomButtonsForDisplayMode(5);
        WfcUtility_SetMainLoopCallback(WfcUtility_EnableMultiNoticeCompletionInput);
    }
}
