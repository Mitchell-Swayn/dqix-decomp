#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020C3984; symbol: func_020c3984; size: 0x1C.
extern "C" void Graphics_WriteSubDisplayModeLowBits(unsigned int value) { volatile unsigned int* p=(volatile unsigned int*)0x04001000; *p=(*p&~7)|value; }
