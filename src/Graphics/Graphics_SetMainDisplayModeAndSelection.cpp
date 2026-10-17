#include <globaldefs.h>
extern "C" unsigned short data_020f226c;extern "C" unsigned short data_02111220;
// Original: arm9/main @ 0x020C391C; symbol: func_020c391c; size: 0x68.
extern "C" ARM void Graphics_SetMainDisplayModeAndSelection(unsigned short mode,unsigned flags,int selection){unsigned short enabled=data_020f226c;unsigned control=*(volatile unsigned*)0x04000000;data_02111220=mode;if(!enabled)mode=0;*(volatile unsigned*)0x04000000=((control&0xfff0fff0)|((unsigned)mode<<16))|flags|(selection<<3);if(!data_02111220)data_020f226c=0;}
