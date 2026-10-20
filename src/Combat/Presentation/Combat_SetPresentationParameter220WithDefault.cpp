#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov025 @ 0x021E8798; symbol: SetGlobalResourceHalfwordFromRecord; size: 0x5C.
// Writes record halfword +8 to global resource +0x220 when positive, 30 when equal to -2, or -1 otherwise.
extern "C" int Combat_SetPresentationParameter220WithDefault(void *record) {
    short value = *(short *)((unsigned char *)record + 8);
    if (value > 0) {
        *(short *)(*(unsigned char **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc) + 0x220) = value;
    } else if (value == -2) {
        *(short *)(*(unsigned char **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc) + 0x220) = 0x1e;
    } else {
        *(short *)(*(unsigned char **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc) + 0x220) = -1;
    }
    return 1;
}
