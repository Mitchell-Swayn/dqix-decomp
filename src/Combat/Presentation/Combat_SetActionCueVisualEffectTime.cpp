#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E6270; symbol: func_ov025_021e6270; size: 0x1C.
extern "C" unsigned Combat_SetActionCueVisualEffectTime(void *object) {
    unsigned value = *(unsigned *)((char *)object + 8);
    char *target = *(char **)((char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    *(unsigned *)(target + 0x548) = value;
    return 1;
}
