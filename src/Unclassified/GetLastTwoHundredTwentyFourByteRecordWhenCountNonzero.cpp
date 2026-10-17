#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205D888; symbol: func_0205d888; size: 0x3C.
extern "C" unsigned char* GetLastTwoHundredTwentyFourByteRecordWhenCountNonzero(unsigned char* p) { if(!*(unsigned int*)(p+0x98))return 0;unsigned char* base=*(unsigned char**)(p+0x9c);if(!base)return 0;unsigned int count=p[0xb4];return count ? base+(count-1)*0xe0 : 0; }
