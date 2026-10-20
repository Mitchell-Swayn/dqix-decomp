#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_RequestTaskRemoval(int, void *);
// Original: arm9/ov031 @ 0x02236E38; symbol: System_DispatchGlobalEntryZeroAndClearWord14; size: 0x28.
// Dispatches global entry zero with the input pointer, then clears word 0x14 in the object stored at data_ov031_02290D04+4.
extern "C" void System_DispatchGlobalEntryZeroAndClearWord14(void *p) {
    WfcUtility_RequestTaskRemoval(0, p);
    *(int *)((char *)*(void **)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage + 4) + 0x14) = 0;
}
