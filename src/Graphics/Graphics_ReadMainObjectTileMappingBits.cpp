#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E2BC4; symbol: func_020e2bc4; size: 0x14.
unsigned int Graphics_ReadMainObjectTileMappingBits(){return (*(volatile unsigned int *)0x04000000&0xe000)>>13;}
}
