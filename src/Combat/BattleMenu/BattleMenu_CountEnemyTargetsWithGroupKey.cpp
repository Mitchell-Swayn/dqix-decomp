#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x02175348; symbol: func_ov000_02175348; size: 0x44.
extern "C" int BattleMenu_CountEnemyTargetsWithGroupKey(unsigned char* base, unsigned value) {
    int length = BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1];
    int count = 0;
    int i = 0;
    for (; i < length; ++i) {
        unsigned entry = *(unsigned*)(base + 0x1d1c + i * 4);
        if (value == entry) ++count;
    }
    return count;
}
