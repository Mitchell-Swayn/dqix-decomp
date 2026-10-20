#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_ArmChoiceInput(void);
// Original: arm9/ov031 @ 0x02229F44; symbol: func_ov031_02229f44; size: 0x2C.
extern "C" void System_InstallCallbackWhenSelectedContextByte9Zero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    WfcUtility_CreateBottomButtonsForDisplayMode(3);
    WfcUtility_SetMainLoopCallback(WfcUtility_ArmChoiceInput);
}
