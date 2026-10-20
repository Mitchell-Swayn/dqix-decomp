#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
// Original data: arm9/ov031 @ 0x2290c58; symbol: data_ov031_02290c58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallSharedByteSetupCallbackWhenObjectAbsent(void);
// Original: arm9/ov031 @ 0x02228910; symbol: func_ov031_02228910; size: 0x50.
extern "C" void WfcUtility_HandleMultiScreenOperationResult(void) {
    int state = WfcUtility_GetDialogSelectionResult();
    if (state != 0) {
        if (state != 1) return;
        WfcUtility_PlaySequenceArchiveEntry(0xe);
        WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage = 1;
    } else {
        WfcUtility_PlaySequenceArchiveEntry(7);
    }
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_InstallSharedByteSetupCallbackWhenObjectAbsent);
}
