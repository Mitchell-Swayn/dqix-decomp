#include <globaldefs.h>
ARM

extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FinishResponsePromptFadeIn(void);
// Original data: arm9/ov031 @ 0x2290c74; symbol: data_ov031_02290c74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0222A418; symbol: func_ov031_0222a418; size: 0x68.
extern "C" void System_ConfigureConditionalDualScreenPlanes(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    if (WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[0] != 0) {
        WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
        WfcUtility_EnableDisplayPlanes(1, 1);
    }
    WfcUtility_SetMainLoopCallback(WfcUtility_FinishResponsePromptFadeIn);
}
