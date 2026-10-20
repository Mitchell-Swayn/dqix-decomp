#include <globaldefs.h>
ARM
extern "C" void *TileGrid_ResolveByKey(void *, unsigned int);
extern "C" void Menu_SetSelectedGridRow(void *, unsigned int);
// Original: arm9/ov004 @ 0x021694E8; symbol: SetTypeSevenHandle101Field28ToOne; size: 0x24.
// Looks up type-seven handle 0x65 and sets its halfword at offset 0x28 to one when found.
extern "C" int ProfileMenu_SelectSecondaryPage(void *state) {
    void *record = TileGrid_ResolveByKey(state, 0x65);
    if (record) Menu_SetSelectedGridRow(record, 1);
    return 0;
}
