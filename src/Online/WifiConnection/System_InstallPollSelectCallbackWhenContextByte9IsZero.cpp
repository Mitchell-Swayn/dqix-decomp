#include <globaldefs.h>
ARM
extern "C" ARM unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_PollAndSelectMainLoopCallback(void);
// Original: arm9/ov031 @ 0x02233F1C; symbol: System_InstallPollSelectCallbackWhenContextByte9IsZero; size: 0x24.
// Tests ReadSelectedContextByte9(0) and installs System_PollAndSelectMainLoopCallback only when the value is zero.
extern "C" void System_InstallPollSelectCallbackWhenContextByte9IsZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0) WfcUtility_SetMainLoopCallback(System_PollAndSelectMainLoopCallback);
}
