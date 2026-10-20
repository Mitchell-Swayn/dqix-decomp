#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback();
// Original data: arm9/ov031 @ 0x2290c74; symbol: data_ov031_02290c74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void Graphics_ConfigureDisplayPlanesAndSelectLoopCallback();
// Original: arm9/ov031 @ 0x0222A5B8; symbol: func_ov031_0222a5b8; size: 0x64.
extern "C" void ConfigureThirdContextAfterTransition() {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    System_SetReadyAndScheduleWordCallback();
    if (WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[1] == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback((void*)Graphics_ConfigureDisplayPlanesAndSelectLoopCallback);
}
