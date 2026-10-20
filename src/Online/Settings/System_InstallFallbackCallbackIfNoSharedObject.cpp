#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_StopSetupTaskAndQueueDisplayExit(void);
// Original: arm9/ov031 @ 0x0222B3B4; symbol: func_ov031_0222b3b4; size: 0x20.
extern "C" void System_InstallFallbackCallbackIfNoSharedObject(void) {
    if (!WfcUtility_IsDialogActive())
        WfcUtility_SetMainLoopCallback(WfcUtility_StopSetupTaskAndQueueDisplayExit);
}
