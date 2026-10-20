#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E5FF0; symbol: func_ov025_021e5ff0; size: 0x20.
extern "C" unsigned CombatOpcode56_SetPresentationParameterAt21C(void *object) {
    unsigned short value = *(unsigned short *)((char *)object + 8);
    char *target = *(char **)((char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    *(unsigned short *)(target + 0x21c) = value;
    return 1;
}
