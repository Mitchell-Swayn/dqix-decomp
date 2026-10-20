#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
extern "C" void PartyMenu_CommitDisplayTransfersAndWindowMasks(void *object);
// Original: arm9/ov017 @ 0x021A5954; symbol: func_ov017_021a5954; size: 0x20.
extern "C" void RunOverlayContextRoutineWhenGlobalObjectPresent(void) {
    void *object = FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
    if (object) PartyMenu_CommitDisplayTransfersAndWindowMasks(object);
}
