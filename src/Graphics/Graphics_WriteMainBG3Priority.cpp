#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A67C; symbol: func_0204a67c; size: 0x1C.
extern "C" void Graphics_WriteMainBG3Priority(unsigned value){volatile unsigned short* p=(volatile unsigned short*)0x0400000e;*p=(*p&~3U)|value;}
