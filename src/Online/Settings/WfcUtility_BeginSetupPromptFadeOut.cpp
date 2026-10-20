#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback(void);
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FinishSetupPromptExit(void);
// Original: arm9/ov031 @ 0x0222B22C; symbol: func_ov031_0222b22c; size: 0x64.
extern "C" void WfcUtility_BeginSetupPromptFadeOut(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    System_SetReadyAndScheduleWordCallback();
    if (WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[0] == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(WfcUtility_FinishSetupPromptExit);
}
