#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback(void);
// Original data: arm9/ov031 @ 0x2290cb0; symbol: data_ov031_02290cb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FinishValidatedScreenTransition(void);
// Original: arm9/ov031 @ 0x02231744; symbol: func_ov031_02231744; size: 0x64.
extern "C" void Overlay_InitializeConditionalLayerAndRegisterCallback(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    System_SetReadyAndScheduleWordCallback();
    if (DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(WfcUtility_FinishValidatedScreenTransition);
}
