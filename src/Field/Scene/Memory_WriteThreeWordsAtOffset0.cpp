#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0218CBCC; symbol: Memory_WriteThreeWordsAtOffset0; size: 0x8.
// Stores three 32-bit words at destination offsets 0, 4, and 8.
extern "C" void Memory_WriteThreeWordsAtOffset0(unsigned int* destination, unsigned int first, unsigned int second, unsigned int third) { destination[0] = first; destination[1] = second; destination[2] = third; }
