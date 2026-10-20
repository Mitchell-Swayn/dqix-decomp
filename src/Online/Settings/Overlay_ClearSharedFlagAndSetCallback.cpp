#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void InitializeIdleSelectionAndSetMainLoopCallback(void);
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222E3A4; symbol: func_ov031_0222e3a4; size: 0x44.
extern "C" void Overlay_ClearSharedFlagAndSetCallback(void) {
    if (WfcUtility_IsDialogActive()) return;
    void* object = WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
    unsigned* word = *(unsigned**)((char*)object + 4);
    *word &= 0xc1fffcff;
    WfcUtility_SetMainLoopCallback(InitializeIdleSelectionAndSetMainLoopCallback);
}
