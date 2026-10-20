#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020D3C08; symbol: func_020d3c08; size: 0x20.
void NpcAttributes_ClearRecords(char *p){memset(p,0,0xb4);*(unsigned int *)(p+0xb4)=0;}
}
