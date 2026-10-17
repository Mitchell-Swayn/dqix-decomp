#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020E2B78; symbol: func_020e2b78; size: 0x1C.
void Graphics_SetSubObjectTileMappingBits(unsigned int v){*(volatile unsigned int *)0x04001000=(*(volatile unsigned int *)0x04001000&~0xe000)|(v<<13);}
}
