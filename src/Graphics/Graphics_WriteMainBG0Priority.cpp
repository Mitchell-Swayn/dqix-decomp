#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A6D0; symbol: func_0204a6d0; size: 0x1C.
extern "C" void Graphics_WriteMainBG0Priority(unsigned value){volatile unsigned short* p=(volatile unsigned short*)0x04000008;*p=(*p&~3U)|value;}
