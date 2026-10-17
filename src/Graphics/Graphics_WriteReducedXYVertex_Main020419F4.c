#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020419F4; symbol: func_020419f4; size: 0x34.
void Graphics_WriteReducedXYVertex_Main020419F4(int x,int y) { short b=y>>8; short a=x>>8; *(volatile unsigned *)0x04000488=(unsigned short)a|((unsigned)(unsigned short)b<<16); }
