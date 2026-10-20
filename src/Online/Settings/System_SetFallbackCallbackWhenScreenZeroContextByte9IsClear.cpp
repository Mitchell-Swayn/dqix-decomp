#include <globaldefs.h>
ARM
extern "C" ARM unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_IncrementScreenCallbackCounter(void);
// Original: arm9/ov031 @ 0x02231A78; symbol: System_SetFallbackCallbackWhenScreenZeroContextByte9IsClear; size: 0x24.
// Installs the fallback callback when screen zero's selected-context byte 9 is clear.
extern "C" void System_SetFallbackCallbackWhenScreenZeroContextByte9IsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0) WfcUtility_SetMainLoopCallback(WfcUtility_IncrementScreenCallbackCounter);
}
