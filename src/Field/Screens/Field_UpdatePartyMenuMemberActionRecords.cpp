#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage[];
extern "C" void PartyMenu_ApplyMultiplayerActionResponses(void *, int, int, int, int);
// Original: arm9/ov017 @ 0x021A5A88; symbol: func_ov017_021a5a88; size: 0x28.
extern "C" void Field_UpdatePartyMenuMemberActionRecords(void *arg0, int arg1, int arg2, int arg3, unsigned char arg4) {
    void *object = *(void **)FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
    if (object != 0)
        PartyMenu_ApplyMultiplayerActionResponses(object, arg1, arg2, arg3, arg4);
}
