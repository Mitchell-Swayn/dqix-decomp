#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d9c; symbol: data_ov031_02290d9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0223E330; symbol: func_ov031_0223e330; size: 0x18.
extern "C" void WfcUtility_SetCallbackQueueEnabled(unsigned int index, unsigned char value) {
    *((unsigned char *)WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage[0] + index * 0x40 + 0x38) = value;
}
