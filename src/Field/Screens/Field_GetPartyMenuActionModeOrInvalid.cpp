#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned *FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021A5A48; symbol: func_ov017_021a5a48; size: 0x20.
extern "C" unsigned Field_GetPartyMenuActionModeOrInvalid(void) {
    unsigned char result = 0xff;
    if (FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage)
        result = *((unsigned char *)FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage + 0x1c79);
    return result;
}
