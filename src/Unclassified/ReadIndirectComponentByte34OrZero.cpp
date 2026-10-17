#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02049444; symbol: func_02049444; size: 0x14.
extern "C" unsigned int ReadIndirectComponentByte34OrZero(unsigned char* p) { unsigned char* v=*(unsigned char**)(p+0x13c); return v ? *(unsigned char*)(v+0x34) : 0x0; }
