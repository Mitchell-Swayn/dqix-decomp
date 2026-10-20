#include <globaldefs.h>
ARM
extern "C" int Graphics_ReplaceCellOamAttributeBits(void *, void *, unsigned int, unsigned int, unsigned short, unsigned int);
// Original: arm9/main @ 0x0205AFB0; symbol: func_0205afb0; size: 0x2C.
// Replaces the selected OAM attribute bit field in every cell object record.
extern "C" void Graphics_SetCellPaletteBank(void *owner, void *cell, unsigned short value)
{
    value &= 15;
    Graphics_ReplaceCellOamAttributeBits(owner, cell, 2, 0xf000, 12, value);
}
