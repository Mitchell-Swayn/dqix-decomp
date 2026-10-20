#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204A7DC; symbol: func_0204a7dc; size: 0x28.
extern "C" void Graphics_SetMainBG1ScrollCoordinates(unsigned x,unsigned y){*(volatile unsigned*)0x04000014=(x&511)|((y<<16)&(511U<<16));}
