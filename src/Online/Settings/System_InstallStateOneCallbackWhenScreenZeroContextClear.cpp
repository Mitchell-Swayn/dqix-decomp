#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_SetMainLoopCallbackUnlessByteIsMinusTwo(void);
// Original: arm9/ov031 @ 0x0222ABBC; symbol: System_InstallStateOneCallbackWhenScreenZeroContextClear; size: 0x2C.
// When screen zero context byte 9 is clear, selects state 1 and installs its callback.
extern "C" void System_InstallStateOneCallbackWhenScreenZeroContextClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0) {
        WfcUtility_CreateBottomButtonsForDisplayMode(1);
        WfcUtility_SetMainLoopCallback(System_SetMainLoopCallbackUnlessByteIsMinusTwo);
    }
}
