#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" {
extern void *data_020fe9a4;
// Original: arm9/main @ 0x02029088; symbol: func_02029088; size: 0x24.
void Graphics_CleanInvalidateCharacterBuffer(){void *p=data_020fe9a4;if(p)CleanInvalidateCacheRange(p,0x6000);}
}
