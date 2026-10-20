#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A73C; symbol: func_0204a73c; size: 0x28.
extern "C" void Graphics_WriteSubBG1Scroll(unsigned x,unsigned y){*(volatile unsigned*)0x04001014=(x&511)|((y<<16)&(511U<<16));}
