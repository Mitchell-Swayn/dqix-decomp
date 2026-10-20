#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
// Original data: arm9/ov031 @ 0x2290cac; symbol: data_ov031_02290cac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[];
extern "C" void System_SetReadyAndScheduleWordCallback(void);
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_AdvanceScreenAfterContextReadiness(void);
// Original: arm9/ov031 @ 0x0223132C; symbol: func_ov031_0223132c; size: 0x74.
extern "C" void WfcMultiScreen_BeginConditionalExitBrightnessTransition(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[0] == 0) System_SetReadyAndScheduleWordCallback();
    if (WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[0] == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(System_AdvanceScreenAfterContextReadiness);
}
