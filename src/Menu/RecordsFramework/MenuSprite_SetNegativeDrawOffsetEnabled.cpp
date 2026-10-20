#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FBA70; symbol: WriteByteAtOffsetB1; size: 0x8.
// Accesses the byte at object offset 0xB1; field meaning is not established.
extern "C" void MenuSprite_SetNegativeDrawOffsetEnabled(void *object, unsigned char value) { *((unsigned char *)object + 0xb1) = value; }
