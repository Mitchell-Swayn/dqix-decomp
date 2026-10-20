#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x0215A920; symbol: func_ov002_0215a920; size: 0x18.
extern "C" void Memory_InitializeFlagAndSentinels(char* p) { p[0] = 0; *(unsigned int*)(p + 4) = 0; *(unsigned int*)(p + 8) = 0xffffffff; }
