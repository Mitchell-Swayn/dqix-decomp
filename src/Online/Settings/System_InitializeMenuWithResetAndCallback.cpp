#include <globaldefs.h>
extern "C" void WfcUtility_CreateConnectionContext(void (*)());
extern "C" void System_InitializeModeCallbacks();
// Original data: arm9/ov031 @ 0x2290c7c; symbol: data_ov031_02290c7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage;
extern "C" void Graphics_LoadMainBG2ScreenAndSetPriorities();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void InitializeOverlayDisplay();
// Original: arm9/ov031 @ 0x0222AABC; symbol: func_ov031_0222aabc; size: 0x4C.
extern "C" void System_InitializeMenuWithResetAndCallback() {
    WfcUtility_CreateConnectionContext(System_InitializeModeCallbacks);
    SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage = 0;
    Graphics_LoadMainBG2ScreenAndSetPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x1c);
    WfcUtility_CreateAnimatedStatusSprite(0);
    WfcUtility_PlaySequenceArchiveEntry(0xb);
    WfcUtility_SetMainLoopCallback(InitializeOverlayDisplay);
}
