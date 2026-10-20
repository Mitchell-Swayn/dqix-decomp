#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290c58; symbol: data_ov031_02290c58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_LoadBG2AndSetFiveBackgroundPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Graphics_ConfigureMode2Masks1And0x15ThenSelectMode3();
// Original: arm9/ov031 @ 0x0222859C; symbol: func_ov031_0222859c; size: 0x48.
extern "C" void WfcUtility_InitializeMultiScreen(void) {
    *WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage = 0;
    Graphics_LoadBG2AndSetFiveBackgroundPriorities();
    System_CreateCopyAndFinalizeResource(0x12);
    WfcUtility_ShowFormattedMessagePanel(0x3b, -1, 0);
    Graphics_SubmitIndexedConfiguredBuffer(0x17);
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureMode2Masks1And0x15ThenSelectMode3);
}
