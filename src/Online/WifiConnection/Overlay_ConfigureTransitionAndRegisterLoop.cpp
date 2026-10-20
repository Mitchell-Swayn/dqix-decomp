#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FinishScreenExitAndDispatchDestination();
// Original data: arm9/ov031 @ 0x2290ce4; symbol: data_ov031_02290ce4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02234B4C; symbol: func_ov031_02234b4c; size: 0x6C.
extern "C" void Overlay_ConfigureTransitionAndRegisterLoop(void) {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    System_SetReadyAndScheduleWordCallback();
    unsigned value = (unsigned char)(WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage + 0xfe);
    if (value <= 1) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(WfcUtility_FinishScreenExitAndDispatchDestination);
}
