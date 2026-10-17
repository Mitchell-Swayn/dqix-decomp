#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/Cache.h"
#include "System/DMA.h"
extern "C" void* Object_ReleaseGlobalResourceUnlessRetained(unsigned);typedef void (*Fill)(void*,int,unsigned);extern "C" Fill data_020f2904[];
// Original: arm9/main @ 0x020DB304; symbol: func_020db304; size: 0x5C.
extern "C" void DMAFillAndInvokeIndexedGraphicsLoader(unsigned kind,unsigned index) {void* data=Object_ReleaseGlobalResourceUnlessRetained(kind);DMAMemsetSynchronous(3,(unsigned)data,0xc0,0x400);CleanInvalidateCacheRange(data,0x400);data_020f2904[index](data,0,0x400);CleanCacheRange(data,0x400);}
