#include <globaldefs.h>
ARM
extern "C" unsigned char *GameState_GetIndexedByteField(void);
// Original: arm9/ov017 @ 0x02191B40; symbol: GameState_ClearIndexedByteField; size: 0x18.
// Resolves the object and index to a byte field and clears that byte when the index is supported.
extern "C" void Field_ClearCombatantAppearanceFlags(void) {
    unsigned char *p = GameState_GetIndexedByteField();
    if (p)
        *p = 0;
}
