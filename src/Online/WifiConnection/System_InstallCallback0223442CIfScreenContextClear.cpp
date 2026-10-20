#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateTimedScreenAndRunEmptyHook(void);
// Original: arm9/ov031 @ 0x02234408; symbol: func_ov031_02234408; size: 0x24.
extern "C" void System_InstallCallback0223442CIfScreenContextClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0)
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateTimedScreenAndRunEmptyHook);
}
