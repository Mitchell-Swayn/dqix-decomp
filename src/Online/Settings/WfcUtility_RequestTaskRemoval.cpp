#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d9c; symbol: data_ov031_02290d9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned *WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage;
extern "C" void PushPointerIntoInterruptProtectedRing(void *, void*);
// Original: arm9/ov031 @ 0x0223E2C0; symbol: func_ov031_0223e2c0; size: 0x20.
extern "C" void WfcUtility_RequestTaskRemoval(unsigned index, void* other) {
    char *entry = (char *)WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage + index * 0x40;
    PushPointerIntoInterruptProtectedRing(*(void **)(entry + 4), other);
}
