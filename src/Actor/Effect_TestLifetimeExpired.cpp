#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02059A2C; symbol: func_02059a2c; size: 0x28.
extern "C" bool Effect_TestLifetimeExpired(unsigned char* p) { if (p[12]) return false; return *(unsigned int*)(p+8)<=*(unsigned int*)(p+4); }
