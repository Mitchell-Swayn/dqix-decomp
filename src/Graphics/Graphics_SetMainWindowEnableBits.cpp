#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E2B94; symbol: func_020e2b94; size: 0x18.
void Graphics_SetMainWindowEnableBits(unsigned int v){*(volatile unsigned int *)0x04000000=(*(volatile unsigned int *)0x04000000&~0xe000)|(v<<13);}
}
