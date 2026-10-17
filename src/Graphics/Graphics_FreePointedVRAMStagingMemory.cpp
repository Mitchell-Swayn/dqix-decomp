#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
extern "C" {
// Original: arm9/main @ 0x020E2478; symbol: func_020e2478; size: 0x18.
void Graphics_FreePointedVRAMStagingMemory(void **p){void *v=*p;if(v==0)return;FreeVRAMStagingMemory(v);}
}
