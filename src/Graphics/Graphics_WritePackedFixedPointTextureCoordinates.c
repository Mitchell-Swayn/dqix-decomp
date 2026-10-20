#include <globaldefs.h>
// Original: arm9/main @ 0x0203FC28; symbol: func_0203fc28; size: 0x34.
ARM void Graphics_WritePackedFixedPointTextureCoordinates(int x,int y){short b=y>>8;short a=x>>8;*(volatile unsigned*)0x04000488=(unsigned short)a|((unsigned)(unsigned short)b<<16);}
