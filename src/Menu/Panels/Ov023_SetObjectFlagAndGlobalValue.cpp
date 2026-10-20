#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned int MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021DBFA8; symbol: func_ov023_021dbfa8; size: 0x28.
extern "C" void Ov023_SetObjectFlagAndGlobalValue(void *object, unsigned int value) {
    if (!value)
        return;
    MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1] = value;
    unsigned int flags = *((unsigned char *)object + 0x79b);
    flags &= ~1u;
    flags |= 1u;
    *((unsigned char *)object + 0x79b) = (unsigned char)flags;
}
