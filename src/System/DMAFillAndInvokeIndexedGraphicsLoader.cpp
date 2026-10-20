#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/Cache.h"
#include "System/DMA.h"
// Original data: arm9/main @ 0x20f2904; symbol: data_020f2904.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 7c590c02d0590c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* DisplayOverlay_GetScreenOAMBuffer(unsigned);typedef void (*Fill)(void*,int,unsigned);extern "C" Fill DMAFillAndInvokeIndexedGraphicsLoader_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020DB304; symbol: func_020db304; size: 0x5C.
extern "C" void DMAFillAndInvokeIndexedGraphicsLoader(unsigned kind,unsigned index) {void* data=DisplayOverlay_GetScreenOAMBuffer(kind);DMAMemsetSynchronous(3,(unsigned)data,0xc0,0x400);CleanInvalidateCacheRange(data,0x400);DMAFillAndInvokeIndexedGraphicsLoader_UnknownRoleProcedureReferenceRecords[index](data,0,0x400);CleanCacheRange(data,0x400);}
