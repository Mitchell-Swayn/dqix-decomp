#include <globaldefs.h>
ARM

// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0223D3D4; symbol: func_ov031_0223d3d4; size: 0x40.
extern "C" int WfcUtility_AreButtonsReleased(unsigned int mask) {
    int blocked = *(volatile unsigned short *)0x027fffa8 & 0x8000;
    if ((blocked >> 15) != 0) {
        return 0;
    }
    void *state = *(void **)(WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage + 4);
    unsigned short flags = *(unsigned short *)((char *)state + 0x36);
    return (mask & flags) == mask;
}
