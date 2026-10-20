#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
// Original data: arm9/ov031 @ 0x2290ce0; symbol: data_ov031_02290ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Graphics_TransitionIdleContextsToMainLoop();
// Original: arm9/ov031 @ 0x02234790; symbol: ConfigureDisplayPlanesAndInstallCallback_02234790; size: 0x64.
// When screen 1 context is clear, resets state, conditionally configures plane tuple (3,1,1,8), then configures (3,0,0x15,8) and installs callback 0x022347F4. Address suffix temporarily disambiguates a similar handler; naming remains pending refinement.
extern "C" void WfcUtility_StartConditionalSubscreenFadeOut() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    System_SetReadyAndScheduleWordCallback();
    if (!OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(Graphics_TransitionIdleContextsToMainLoop);
}
