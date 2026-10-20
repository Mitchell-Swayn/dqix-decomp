#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback();
// Original data: arm9/ov031 @ 0x2290cc8; symbol: data_ov031_02290cc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Network_TransitionMainLoopFromSelectedMode();
// Original: arm9/ov031 @ 0x02233720; symbol: func_ov031_02233720; size: 0x64.
extern "C" void System_ConfigureSecondaryDisplayMode() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[2] != 0) System_SetReadyAndScheduleWordCallback();
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x14, 8);
    WfcUtility_SetMainLoopCallback(Network_TransitionMainLoopFromSelectedMode);
}
