#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
// Original data: arm9/ov031 @ 0x2290cb8; symbol: data_ov031_02290cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetReadyAndScheduleWordCallback(void);
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcStepThreeScreen_FinishTransition(void);
// Original: arm9/ov031 @ 0x02231E18; symbol: func_ov031_02231e18; size: 0x74.
extern "C" void WfcStepThreeScreen_BeginConditionalExitBrightnessTransition(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage == 0) System_SetReadyAndScheduleWordCallback();
    if (Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x14, 8);
    WfcUtility_SetMainLoopCallback((void*)WfcStepThreeScreen_FinishTransition);
}
