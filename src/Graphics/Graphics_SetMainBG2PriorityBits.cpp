#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204A698; symbol: func_0204a698; size: 0x1C.
void Graphics_SetMainBG2PriorityBits(unsigned int v){*(volatile unsigned short *)0x0400000c=(*(volatile unsigned short *)0x0400000c&~3)|v;}
}
