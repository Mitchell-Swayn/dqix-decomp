#include <globaldefs.h>
#include <System/Cache.h>
#include <System/DMA.h>
struct Context {char pad[0x3c];unsigned char bank;char pad3d[20];unsigned char active,pad52,flag;char pad54[4];void* handle;};
extern "C" unsigned Graphics_ComputeObjectVRAMCapacity(unsigned),Graphics_ReadObjectMappingAlignmentShift(unsigned);
extern "C" void Graphics_GetGlobalOamTransferState();
extern "C" void* DisplayOverlay_GetScreenOAMBuffer(Context*,unsigned);
extern "C" void DisplayOverlay_SetSelectedScreenSpriteUpdates(Context*,int),DisplayOverlay_WriteScreenCoverSprites(Context*,unsigned),DisplayOverlay_AdvanceThreeSpriteAnimations(Context*,unsigned),Graphics_SetSelectedScreenBrightnessAndMarkEnabled(Context*,unsigned,int,int);
// Original data: arm9/main @ 0x20f2904; symbol: data_020f2904.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 7c590c02d0590c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void (*DMAFillAndInvokeIndexedGraphicsLoader_UnknownRoleProcedureReferenceRecords[])(void*,int,unsigned);
// Original data: arm9/main @ 0x20f28f4; symbol: data_020f28f4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3caf0d0220af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void (*GraphicsFlushAndUploadActiveBankData_UnknownRoleProcedureReferenceRecords[])(void*);
// Original: arm9/main @ 0x020DB5EC; symbol: func_020db5ec; size: 0xF8.
extern "C" void Graphics_FlushAndUploadActiveBankData(Context* p){if(!p->active)return;unsigned size=Graphics_ComputeObjectVRAMCapacity(p->bank);unsigned shift=Graphics_ReadObjectMappingAlignmentShift(p->bank);unsigned second=(size-0xb80)>>shift,first=(size-0x800)>>shift;Graphics_GetGlobalOamTransferState();void* data=DisplayOverlay_GetScreenOAMBuffer(p,p->bank);DisplayOverlay_SetSelectedScreenSpriteUpdates(p,0);if(p->flag)DisplayOverlay_WriteScreenCoverSprites(p,first);DisplayOverlay_AdvanceThreeSpriteAnimations(p,second);CleanInvalidateCacheRange(data,0xe0);DMAFillAndInvokeIndexedGraphicsLoader_UnknownRoleProcedureReferenceRecords[p->bank](data,0,0xe0);CleanCacheRange(data,0xe0);DMAMemsetSynchronous(3,(unsigned)data+0x20,0xc0,0x60);Graphics_SetSelectedScreenBrightnessAndMarkEnabled(p,p->bank,0,0);GraphicsFlushAndUploadActiveBankData_UnknownRoleProcedureReferenceRecords[p->bank](p->handle);}
