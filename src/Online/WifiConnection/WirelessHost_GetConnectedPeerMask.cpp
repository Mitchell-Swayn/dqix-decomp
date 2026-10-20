#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02239BD4; symbol: func_ov031_02239bd4; size: 0x14.
extern "C" unsigned WirelessHost_GetConnectedPeerMask(void) {
    unsigned *object = *(unsigned **)((char *)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    return *(unsigned short *)((char *)object + 0x52);
}
