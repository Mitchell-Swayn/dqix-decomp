#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateTimedNoticeWait(void);
// Original: arm9/ov031 @ 0x0222B52C; symbol: func_ov031_0222b52c; size: 0x24.
extern "C" void System_InstallCallbackIfScreenZeroContextByteIsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0)
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateTimedNoticeWait);
}
