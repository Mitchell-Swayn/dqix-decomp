#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E16DC; symbol: func_020e16dc; size: 0x18.
extern "C" void Window_SetPaletteColor(unsigned char* p,int i,unsigned short value) { if (i<0) return; if (i<2) *(unsigned short*)(p+i*2+0x22)=value; }
