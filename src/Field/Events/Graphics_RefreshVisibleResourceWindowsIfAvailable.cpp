#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d8478; symbol: data_ov017_021d8478.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage;
extern "C" void Ov003_RefreshVisibleResourceWindows(void *state);
// Original: arm9/ov017 @ 0x021C166C; symbol: Graphics_RefreshVisibleResourceWindowsIfAvailable; size: 0x20.
// Refreshes visible resource windows when the global state pointer is available.
extern "C" void Graphics_RefreshVisibleResourceWindowsIfAvailable(void) {
    void *state = FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage;
    if (state != 0) Ov003_RefreshVisibleResourceWindows(state);
}
