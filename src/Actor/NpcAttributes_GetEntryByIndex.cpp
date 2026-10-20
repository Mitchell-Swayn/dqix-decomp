#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D3D78; symbol: func_020d3d78; size: 0x18.
char *NpcAttributes_GetEntryByIndex(char *p,int i){if(i<*(int *)(p+0xb4))return p+i*36;return 0;}
}
