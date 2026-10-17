#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A628; symbol: func_0204a628; size: 0x1C.
extern "C" void Graphics_WriteSubBG2Priority(unsigned value){volatile unsigned short* p=(volatile unsigned short*)0x0400100c;*p=(*p&~3U)|value;}
