#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FBA78; symbol: Object_WriteByteAtOffsetB0; size: 0x8.
// Stores the supplied byte at object offset 0xb0; field meaning is unknown.
extern "C" void MenuSprite_SetPositiveDrawOffsetEnabled(void* self, unsigned char value) { *((unsigned char*)self + 0xb0) = value; }
