#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMainBG2AssetsAndSetPriorities(void);
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void Graphics_ConfigureMode2Masks1And0x15ThenSelectMode6(void);
// Original data: arm9/ov031 @ 0x2290ce0; symbol: data_ov031_02290ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02234520; symbol: Unclassified_InitializeModeThirtyEightAndInstallCallback; size: 0x50.
// Clears data_ov031_02290ce0[0], runs the startup helper sequence including mode 0x38 and values 8, 1, and 0x27, then installs the next callback.
extern "C" void WfcUtility_InitializeMessageScreenWithAnimatedHeader(void) {
    OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage[0] = 0;
    Graphics_LoadMainBG2AssetsAndSetPriorities();
    System_CreateCopyAndFinalizeResource(8);
    int type = 0x38;
    WfcUtility_ShowFormattedMessagePanel(type, type - 0x39, 0);
    WfcUtility_ConfigureSecondaryControlsForDisplayMode(1);
    Graphics_SubmitIndexedConfiguredBuffer(0x27);
    WfcUtility_SetMainLoopCallback((void*)Graphics_ConfigureMode2Masks1And0x15ThenSelectMode6);
}
