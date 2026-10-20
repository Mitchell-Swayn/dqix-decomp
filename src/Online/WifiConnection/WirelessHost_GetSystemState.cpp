#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02239BE8; symbol: func_ov031_02239be8; size: 0x14.
extern "C" unsigned int WirelessHost_GetSystemState(void) {
    return *(unsigned int *)((char *)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] + 0x40);
}
