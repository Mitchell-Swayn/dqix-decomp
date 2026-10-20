#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021537C8; symbol: Memory_WriteThreeWordsAtOffset4; size: 0x8.
// Stores three 32-bit words at destination offsets 4, 8, and 0x0c.
extern "C" void Memory_WriteThreeWordsAtOffset4(unsigned int* destination, unsigned int first, unsigned int second, unsigned int third) { destination[1] = first; destination[2] = second; destination[3] = third; }
