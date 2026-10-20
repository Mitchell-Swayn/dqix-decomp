#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x021744F4; symbol: func_ov000_021744f4; size: 0x10.
extern "C" void Ov000_SetPointerAtOffset4(void *unused, void *value) {
    *(void **)(BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage + 4) = value;
}
