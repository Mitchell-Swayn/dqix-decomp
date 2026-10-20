#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c6c; symbol: data_ov031_02290c6c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_InitializeBG2ScreenLoaderAndPriorities(void);
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureDualDisplayPlanes(void);
// Original: arm9/ov031 @ 0x02229E28; symbol: func_ov031_02229e28; size: 0x48.
extern "C" void Overlay_InitializeStartupSceneAndRegisterCallback(void) {
    DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage[0] = 0;
    Graphics_InitializeBG2ScreenLoaderAndPriorities();
    System_CreateCopyAndFinalizeResource(0x13);
    int mode = 0x3c;
    int offset = mode - 0x3d;
    WfcUtility_ShowFormattedMessagePanel(mode, offset, 0);
    Graphics_SubmitIndexedConfiguredBuffer(0x1b);
    WfcUtility_SetMainLoopCallback(System_ConfigureDualDisplayPlanes);
}
