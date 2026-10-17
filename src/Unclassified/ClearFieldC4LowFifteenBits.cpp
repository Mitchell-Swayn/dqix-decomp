#include <globaldefs.h>

// Original: arm9/main @ 0x0203409C; symbol: func_0203409c; size: 0x18.
extern "C" ARM void ClearFieldC4LowFifteenBits (char* p) { *(unsigned short*)(p+0xc4) &= ~0x7fff; }
