#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive();
// Original data: arm9/ov031 @ 0x2290ce4; symbol: data_ov031_02290ce4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetSharedByte18AndRegisterTransitionCallback();
extern "C" void WfcUtility_BeginScreenExitForMode();
extern "C" void WfcUtility_UpdateCancelInputAndBeginTransition();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_EnableBottomButtonTouch();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void Wireless_SetUsbAccessPointScanCallback(unsigned int);
// Original: arm9/ov031 @ 0x02234E40; symbol: System_SelectMainLoopCallbackFromSharedState; size: 0x68.
// Selects the next callback from shared-object presence and the global control byte; the fallback path dispatches mode 0xB and clears that byte.
extern "C" void System_SelectMainLoopCallbackFromSharedState() {
    if (WfcUtility_IsDialogActive()) return;
    if (WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage == 1) {
        WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterTransitionCallback);
        return;
    }
    WfcUtility_PlaySequenceArchiveEntry(0xb);
    WfcUtility_EnableBottomButtonTouch();
    WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage = 0;
    Wireless_SetUsbAccessPointScanCallback((unsigned int)WfcUtility_BeginScreenExitForMode);
    WfcUtility_SetMainLoopCallback(WfcUtility_UpdateCancelInputAndBeginTransition);
}
