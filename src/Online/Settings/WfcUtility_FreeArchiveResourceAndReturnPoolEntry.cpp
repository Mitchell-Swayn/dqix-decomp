#include <globaldefs.h>
ARM

extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **p);
// Original data: arm9/ov031 @ 0x2290d24; symbol: data_ov031_02290d24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage[];
extern "C" void PushPointerIntoInterruptProtectedRing(void *, void *);

// Original: arm9/ov031 @ 0x0223B710; symbol: func_ov031_0223b710; size: 0x34.
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void *allocation, void *unused1, void *unused2, void *unused3) {
    WfcUtility_FreeAllocationAndClearPointer(&allocation);
    void *owner = *(void **)WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage;
    PushPointerIntoInterruptProtectedRing(*(void **)((char *)owner + 0x84), allocation);
}
