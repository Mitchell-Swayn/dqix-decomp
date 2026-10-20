#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov025 @ 0x021E6EF8; symbol: func_ov025_021e6ef8; size: 0x28.
extern "C" int Memory_CopyObjectHalfwordsToGlobalContext(void *object) {
    short second = *(short *)((unsigned char *)object + 0x0a);
    unsigned short first = *(unsigned short *)((unsigned char *)object + 8);
    *(unsigned short *)((unsigned char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x57e) = first;
    *(short *)((unsigned char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x580) = second;
    return 1;
}
