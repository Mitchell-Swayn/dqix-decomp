#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204A644; symbol: func_0204a644; size: 0x1C.
void Graphics_SetSubBG1PriorityBits(unsigned int v){*(volatile unsigned short *)0x0400100a=(*(volatile unsigned short *)0x0400100a&~3)|v;}
}
