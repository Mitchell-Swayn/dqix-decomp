#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1D3C; symbol: Unclassified_SetByteAtOffset49; size: 0x8.
// Stores the low byte of the second argument at byte offset 0x49.
extern "C" void KrakPot_SetFieldMenuDirectMode(void *self, unsigned int value) { *((unsigned char *)self + 0x49) = value; }
