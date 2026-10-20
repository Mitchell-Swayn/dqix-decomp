#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_EnablePendingInputAfterMessageReady(void);
// Original: arm9/ov031 @ 0x02234A3C; symbol: func_ov031_02234a3c; size: 0x2C.
extern "C" void System_InstallAlternateCallbackWhenSelectedContextByte9Zero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    WfcUtility_CreateBottomButtonsForDisplayMode(2);
    WfcUtility_SetMainLoopCallback(WfcUtility_EnablePendingInputAfterMessageReady);
}
