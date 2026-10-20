#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void System_SetCallbackWhenSharedByte22NotMinusTwo(void);
// Original: arm9/ov031 @ 0x02228A58; symbol: func_ov031_02228a58; size: 0x2C.
extern "C" void System_InstallCallbackWhenScreenZeroIsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(5);
    WfcUtility_SetMainLoopCallback(System_SetCallbackWhenSharedByte22NotMinusTwo);
}
