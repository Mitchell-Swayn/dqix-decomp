#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020DAF3C; symbol: func_020daf3c; size: 0x18.
void Graphics_SetMainDisplayModeBitsEightThroughTwelve(unsigned int v){*(volatile unsigned int *)0x04000000=(*(volatile unsigned int *)0x04000000&~0x1f00)|(v<<8);}
}
