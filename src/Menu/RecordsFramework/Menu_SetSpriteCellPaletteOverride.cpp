#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB274; symbol: WriteByteAtOffset38; size: 0x8.
// Accesses the byte at object offset 0x38; field meaning is not established.
extern "C" void Menu_SetSpriteCellPaletteOverride(void *object, unsigned char value) { *((unsigned char *)object + 0x38) = value; }
