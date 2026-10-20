#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_StartHeaderRightmostSpriteRetraction();
extern "C" void WfcUtility_DisableBottomButtonTouch();
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_BeginProfileSelectionExit();
// Original: arm9/ov031 @ 0x02232A84; symbol: func_ov031_02232a84; size: 0x3C.
extern "C" void ConfigureSecondContextDisplay() {
    if (*(unsigned char*)(*(unsigned*)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage + 4) + 0x1d) == 2) WfcUtility_StartHeaderRightmostSpriteRetraction();
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_BeginProfileSelectionExit);
}
