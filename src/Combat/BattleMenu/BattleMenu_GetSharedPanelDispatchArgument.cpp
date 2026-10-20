#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x02174504; symbol: func_ov000_02174504; size: 0x10.
extern "C" unsigned int BattleMenu_GetSharedPanelDispatchArgument(void) { return BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]; }
