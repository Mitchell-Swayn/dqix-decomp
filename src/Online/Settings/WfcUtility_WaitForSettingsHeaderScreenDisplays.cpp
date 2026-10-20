#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_RunEmptyIdleHooks(void);
// Original: arm9/ov031 @ 0x02233C40; symbol: func_ov031_02233c40; size: 0x34.
extern "C" void WfcUtility_WaitForSettingsHeaderScreenDisplays(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) == 0 && WfcUtility_IsScreenTransitionBusy(0) == 0) {
        WfcUtility_SetMainLoopCallback(WfcUtility_RunEmptyIdleHooks);
    }
}
