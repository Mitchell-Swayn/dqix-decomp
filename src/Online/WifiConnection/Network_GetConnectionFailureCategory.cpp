#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022134F0; symbol: func_ov031_022134f0; size: 0x14.
extern "C" unsigned int Network_GetConnectionFailureCategory(void) {
    unsigned char *p = (unsigned char *)&NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage;
    p = *(unsigned char **)(p + 0xc);
    return *(unsigned int *)(p + 0xc);
}
