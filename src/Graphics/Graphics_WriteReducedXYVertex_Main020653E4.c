#include <globaldefs.h>
// Original: arm9/main @ 0x020653E4; symbol: func_020653e4; size: 0x34.
ARM void Graphics_WriteReducedXYVertex_Main020653E4(int x,int y){short b=y>>8;short a=x>>8;*(volatile unsigned*)0x04000488=(unsigned short)a|((unsigned)(unsigned short)b<<16);}
