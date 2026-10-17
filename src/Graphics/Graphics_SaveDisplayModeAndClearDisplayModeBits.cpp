#include <globaldefs.h>
ARM
extern "C" unsigned short data_020f226c;extern "C" unsigned short data_02111220;
// Original: arm9/main @ 0x020C3898; symbol: func_020c3898; size: 0x3C.
extern "C" void Graphics_SaveDisplayModeAndClearDisplayModeBits() { volatile unsigned int* reg=(volatile unsigned int*)0x04000000;unsigned int old=*reg;data_020f226c=0;data_02111220=(old&0x30000)>>16;*reg=old&~0x30000; }
