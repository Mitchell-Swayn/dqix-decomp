#include <globaldefs.h>
ARM

extern "C" int WfcUtility_GetBottomButtonSelection();
extern "C" void WfcUtility_StopSequenceImmediately();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByte18AndRegisterTransitionCallback(void);
// Original data: arm9/ov031 @ 0x2290ce4; symbol: data_ov031_02290ce4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x02234AE0; symbol: func_ov031_02234ae0; size: 0x4C.
extern "C" void System_InitializeCallbackAfterSharedByteChecks(void) {
    if (WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage != 0) return;
    if (WfcUtility_GetBottomButtonSelection() != 0) return;
    WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage = 2;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterTransitionCallback);
}
