#include <globaldefs.h>
ARM
extern "C" unsigned char *GameState_GetIndexedByteField(void);
// Original: arm9/ov017 @ 0x02191B58; symbol: GameState_ReadIndexedByteFieldOrZero; size: 0x18.
// Returns the selected indexed byte, or zero when the object and index do not resolve to a byte field.
extern "C" unsigned int Field_GetCombatantAppearanceFlags(void) {
    unsigned char *p = GameState_GetIndexedByteField();
    return p ? *p : 0;
}
