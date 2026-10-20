#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage[];
extern "C" void Ov002_InitializeSelectionFlags(void *);
// Original: arm9/ov017 @ 0x021A5AB0; symbol: func_ov017_021a5ab0; size: 0x20.
extern "C" void Field_ResetPartyMenuSelectionFlagsIfOpen(void) {
    void *object = *(void **)FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
    if (object != 0)
        Ov002_InitializeSelectionFlags(object);
}
