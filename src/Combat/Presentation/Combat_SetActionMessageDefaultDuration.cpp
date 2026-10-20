#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E85A8; symbol: func_ov025_021e85a8; size: 0x20.
extern "C" int Combat_SetActionMessageDefaultDuration(void *p) {
    void *base = *(void **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    *(unsigned short *)((char *)base + 0x74a) = *(unsigned short *)((char *)p + 8);
    return 1;
}
