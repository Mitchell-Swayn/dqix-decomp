#include <globaldefs.h>
ARM
extern "C" void WfcUtility_LoadResponsePromptBackground(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" unsigned WfcUtility_ShowFormattedMessagePanel(unsigned, int, unsigned);
// Original data: arm9/ov031 @ 0x2290c74; symbol: data_ov031_02290c74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_ConfigureConditionalDualScreenPlanes(void);
// Original: arm9/ov031 @ 0x0222A35C; symbol: func_ov031_0222a35c; size: 0x3C.
extern "C" void WfcUtility_InitializeResponsePrompt(void) {
    WfcUtility_LoadResponsePromptBackground();
    Graphics_SubmitIndexedConfiguredBuffer(0x20);
    WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage = (unsigned char)WfcUtility_ShowFormattedMessagePanel(0x3c, -1, 0);
    WfcUtility_SetMainLoopCallback((void*)System_ConfigureConditionalDualScreenPlanes);
}
