#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x0215373C; symbol: Memory_WriteWordAtOffset0; size: 0x8.
// Stores one 32-bit word at the destination base.
extern "C" void Memory_WriteWordAtOffset0(unsigned int* destination, unsigned int value) { *destination = value; }
