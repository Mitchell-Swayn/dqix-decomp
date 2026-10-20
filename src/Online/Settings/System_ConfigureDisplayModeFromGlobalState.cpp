#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback();
// Original data: arm9/ov031 @ 0x2290c58; symbol: data_ov031_02290c58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Graphics_ConfigureDisplayPlanesForPrimaryContextMode();
// Original: arm9/ov031 @ 0x022287F4; symbol: func_ov031_022287f4; size: 0x64.
extern "C" void System_ConfigureDisplayModeFromGlobalState() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    System_SetReadyAndScheduleWordCallback();
    if (WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureDisplayPlanesForPrimaryContextMode);
}
