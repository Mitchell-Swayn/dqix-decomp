#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9B6C; symbol: Menu_ReadGridEntryOrZero; size: 0x34.
// Maintains indexed menu record slots and grid access.
struct Grid { char padding[0x20]; unsigned short* entries; unsigned short rows, columns; };
extern "C" unsigned short Menu_ReadGridEntryOrZero(Grid* self, unsigned row, unsigned column) {
 if (!self->entries) return 0;
 if (!(self->rows > row && self->columns > column)) return 0;
 return self->entries[row*self->columns+column];
}
