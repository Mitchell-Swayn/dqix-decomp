#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E2AB0; symbol: func_020e2ab0; size: 0x28.
extern "C" void Graphics_SetSubWindowZeroInsideMask(unsigned value,int enabled){unsigned v=(*(volatile unsigned short*)0x04001048&~63U)|value;if(enabled)v|=32;*(volatile unsigned short*)0x04001048=v;}
