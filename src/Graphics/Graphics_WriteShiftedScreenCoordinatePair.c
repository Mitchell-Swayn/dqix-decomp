#include <globaldefs.h>
// Original: arm9/main @ 0x02047888; symbol: func_02047888; size: 0x34.
ARM void Graphics_WriteShiftedScreenCoordinatePair(int x,int y){short b=y>>8;short a=x>>8;*(volatile unsigned*)0x04000488=(unsigned short)a|((unsigned)(unsigned short)b<<16);}
