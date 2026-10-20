#include <globaldefs.h>
ARM
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **p);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02235C5C; symbol: func_ov031_02235c5c; size: 0x14.
extern "C" void Memory_FreeSharedAllocationAndClearFlag(void) {
    WfcUtility_FreeAllocationAndClearPointer(&NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage);
}
