#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive();
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_SelectMainLoopFromContextState();
// Original: arm9/ov031 @ 0x0222A908; symbol: func_ov031_0222a908; size: 0x5C.
extern "C" void ConfigureThirdContextFromSharedState() {
    if (WfcUtility_IsDialogActive()) return;
    if (ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[1] == 0) WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback((void*)System_SelectMainLoopFromContextState);
}
