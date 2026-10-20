#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E2B28; symbol: func_020e2b28; size: 0x28.
extern "C" void Graphics_SetSubOutsideWindowMask(unsigned value,int enabled){unsigned v=(*(volatile unsigned short*)0x0400104a&~63U)|value;if(enabled)v|=32;*(volatile unsigned short*)0x0400104a=v;}
