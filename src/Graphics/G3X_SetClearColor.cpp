#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020C5588; symbol: func_020c5588; size: 0x28.
extern "C" void G3X_SetClearColor(unsigned a,unsigned b,unsigned short c,unsigned d,int enabled){unsigned v=a|(b<<16)|(d<<24);if(enabled)v|=0x8000;*(volatile unsigned*)0x04000350=v;*(volatile unsigned short*)0x04000354=c;}
