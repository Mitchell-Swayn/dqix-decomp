#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void System_HandleInputAndAdvanceState();
// Original: arm9/ov031 @ 0x0222EEC4; symbol: func_ov031_0222eec4; size: 0x34.
extern "C" void System_InstallInputStateCallbackWhenBothContextBytesAreClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_SetMainLoopCallback(System_HandleInputAndAdvanceState);
}
