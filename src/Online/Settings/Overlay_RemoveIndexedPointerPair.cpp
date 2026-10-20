#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290d9c; symbol: data_ov031_02290d9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**);
extern "C" void WfcUtility_UnlinkListNode(void*);
extern "C" void PushPointerIntoInterruptProtectedRing(void*, void*);
// Original: arm9/ov031 @ 0x0223E2EC; symbol: func_ov031_0223e2ec; size: 0x44.
extern "C" void Overlay_RemoveIndexedPointerPair(unsigned index, void* pair) {
    if (*((unsigned char*)pair + 0x11) != 0) WfcUtility_FreeAllocationAndClearPointer((void**)((char*)pair + 0xc));
    WfcUtility_UnlinkListNode(pair);
    PushPointerIntoInterruptProtectedRing(*(void**)((char*)*(void**)WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage + index * 0x40), pair);
}
