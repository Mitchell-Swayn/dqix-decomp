#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A764; symbol: func_0204a764; size: 0x28.
extern "C" void Graphics_SetSubBG0ScrollCoordinates(unsigned x,unsigned y){*(volatile unsigned*)0x04001010=(x&511)|((y<<16)&(511U<<16));}
