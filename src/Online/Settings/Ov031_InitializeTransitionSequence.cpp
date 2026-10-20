#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290cb4; symbol: data_ov031_02290cb4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031InitializeTransitionSequence_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_StartMainDisplayCounterScreenTransition();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231988; symbol: func_ov031_02231988; size: 0x3C.
extern "C" ARM void Ov031_InitializeTransitionSequence() {
    Ov031InitializeTransitionSequence_UnknownRoleZeroInitializedStorage[0] = 0;
    Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities();
    System_ConvertSharedRegionByteToIndexPlusFive();
    Graphics_SubmitIndexedConfiguredBuffer(0x26);
    WfcUtility_PlaySequenceArchiveEntry(0x10);
    WfcUtility_SetMainLoopCallback(WfcUtility_StartMainDisplayCounterScreenTransition);
}
