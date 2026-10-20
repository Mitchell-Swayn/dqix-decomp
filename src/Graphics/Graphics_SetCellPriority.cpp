#include <globaldefs.h>
ARM
extern "C" int Graphics_ReplaceCellOamAttributeBits(void *, void *, unsigned int, unsigned int, unsigned short, unsigned int);
// Original: arm9/main @ 0x0205AF84; symbol: func_0205af84; size: 0x2C.
// Replaces the selected OAM attribute bit field in every cell object record.
extern "C" void Graphics_SetCellPriority(void *owner, void *cell, unsigned short value)
{
    value &= 3;
    Graphics_ReplaceCellOamAttributeBits(owner, cell, 2, 0xc00, 10, value);
}
