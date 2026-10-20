#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
extern "C" void PartyMenu_SetMultiplayerItemActionMessage(void *);
// Original: arm9/ov017 @ 0x021A5A28; symbol: Resource_ProcessOverlayStateIfPresent; size: 0x20.
// Passes the global overlay-state pointer to its processor when it is nonnull.
extern "C" void Resource_ProcessOverlayStateIfPresent(void) {
    void *state = FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
    if (state != 0) PartyMenu_SetMultiplayerItemActionMessage(state);
}
