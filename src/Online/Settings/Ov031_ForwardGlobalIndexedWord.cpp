#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d60; symbol: data_ov031_02290d60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;
extern "C" int WfcUtility_PopPointerRingBack(unsigned int value);
// Original: arm9/ov031 @ 0x0223DA38; symbol: func_ov031_0223da38; size: 0x20.
extern "C" int Ov031_ForwardGlobalIndexedWord(unsigned int index) {
    unsigned int value = *(unsigned int *)(WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage + index * 4 + 0x800);
    return WfcUtility_PopPointerRingBack(value);
}
