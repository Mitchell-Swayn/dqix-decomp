#include <globaldefs.h>

// Original: arm9/main @ 0x020340D4; symbol: func_020340d4; size: 0x10.
extern "C" ARM unsigned int ReadFieldC2HighBit (unsigned char* p) { return ((unsigned int)p[0xc2] << 24) >> 31; }
