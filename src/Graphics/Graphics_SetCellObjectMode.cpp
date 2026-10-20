#include <globaldefs.h>
ARM
extern "C" int Graphics_ReplaceCellOamAttributeBits(void *, void *, unsigned int, unsigned int, unsigned short, unsigned int);
// Original: arm9/main @ 0x0205AFDC; symbol: func_0205afdc; size: 0x2C.
// Replaces the selected OAM attribute bit field in every cell object record.
extern "C" void Graphics_SetCellObjectMode(void *owner, void *cell, unsigned short value)
{
    value &= 3;
    Graphics_ReplaceCellOamAttributeBits(owner, cell, 0, 0xc00, 10, value);
}
