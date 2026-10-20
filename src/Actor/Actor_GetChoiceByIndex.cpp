#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209BD80; symbol: func_0209bd80; size: 0x14.
extern "C" unsigned char* Actor_GetChoiceByIndex(unsigned char* p,int i) { if (*(int*)(p+0xc0)<=i) return 0; return p+i*32; }
