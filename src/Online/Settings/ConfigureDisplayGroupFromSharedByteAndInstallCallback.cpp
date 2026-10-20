#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_DisableBottomButtonTouch();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_ReleaseAccessPointListAndOpenSelection();
// Original: arm9/ov031 @ 0x0222C148; symbol: ConfigureDisplayGroupFromSharedByteAndInstallCallback; size: 0x70.
// When screen 1 context is clear, chooses an action from shared byte +0x54, configures display group 3, and installs the next callback.
extern "C" void ConfigureDisplayGroupFromSharedByteAndInstallCallback(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0)
        return;
    unsigned char *shared = (unsigned char *)*(void **)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 1);
    if (shared[0x54] != 0)
        System_SetReadyAndScheduleWordCallback();
    else
        WfcUtility_DisableBottomButtonTouch();
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x1d, 8);
    WfcUtility_SetMainLoopCallback(WfcUtility_ReleaseAccessPointListAndOpenSelection);
}
