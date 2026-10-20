#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void CreateSharedDisplayResource();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_SelectMainLoopCallbackFromSharedState();
// Original data: arm9/ov031 @ 0x2290ce4; symbol: data_ov031_02290ce4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02234DE4; symbol: func_ov031_02234de4; size: 0x5C.
extern "C" void System_SelectTransitionCallbackBySharedMode(void) {
    int mode = WfcUtility_GetDialogSelectionResult();
    if (mode == 0) goto zero;
    if (mode != 1) return;
    WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage[0] = 3;
    WfcUtility_PlaySequenceArchiveEntry(6);
    goto common;
zero:
    WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage[0] = 1;
    WfcUtility_PlaySequenceArchiveEntry(7);
common:
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_SelectMainLoopCallbackFromSharedState);
}
