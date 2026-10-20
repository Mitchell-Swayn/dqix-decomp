#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void System_InvokeOwnerCallbackAndInstallNextCallback();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(int mode);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void DispatchTaskModeAndSetMainLoopCallback();
// Original: arm9/ov031 @ 0x0222DE24; symbol: func_ov031_0222de24; size: 0x30.
extern "C" void System_InstallCallbackIfContextByteClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    System_InvokeOwnerCallbackAndInstallNextCallback();
    WfcUtility_PlaySequenceArchiveEntry(0x15);
    WfcUtility_SetMainLoopCallback(DispatchTaskModeAndSetMainLoopCallback);
}
