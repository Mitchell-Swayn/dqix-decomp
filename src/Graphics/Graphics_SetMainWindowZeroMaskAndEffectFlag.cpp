#include <globaldefs.h>
// Original: arm9/main @ 0x020E2B00; symbol: func_020e2b00; size: 0x28.
extern "C" ARM void Graphics_SetMainWindowZeroMaskAndEffectFlag(unsigned short mode,int enable){unsigned value=(*(volatile unsigned short*)0x04000048&~0x3f)|mode;if(enable)value|=32;*(volatile unsigned short*)0x04000048=value;}
