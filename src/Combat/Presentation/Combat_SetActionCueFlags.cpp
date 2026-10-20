#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E6304; symbol: func_ov025_021e6304; size: 0x1C.
extern "C" int Combat_SetActionCueFlags(void *p) {
    unsigned int value = *(unsigned int *)((unsigned char *)p + 8);
    *(unsigned int *)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x558) = value;
    return 1;
}
