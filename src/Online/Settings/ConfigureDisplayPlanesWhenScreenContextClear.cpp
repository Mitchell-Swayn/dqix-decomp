#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
// Original data: arm9/ov031 @ 0x2290c5c; symbol: data_ov031_02290c5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_CloseOptionsMenuAndOpenSelection();
// Original: arm9/ov031 @ 0x02229548; symbol: ConfigureDisplayPlanesWhenScreenContextClear; size: 0x64.
// When screen 1 context byte 9 is clear, optionally resets state, configures plane tuples (3,1,1,8) and (3,0,0x14,8), then installs callback 0x022295AC.
extern "C" void ConfigureDisplayPlanesWhenScreenContextClear() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (*(&WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage + 1)) System_SetReadyAndScheduleWordCallback();
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x14, 8);
    WfcUtility_SetMainLoopCallback(WfcUtility_CloseOptionsMenuAndOpenSelection);
}
