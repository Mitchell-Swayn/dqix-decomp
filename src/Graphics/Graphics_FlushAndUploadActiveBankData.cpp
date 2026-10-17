#include <globaldefs.h>
#include <System/Cache.h>
#include <System/DMA.h>
struct Context {char pad[0x3c];unsigned char bank;char pad3d[20];unsigned char active,pad52,flag;char pad54[4];void* handle;};
extern "C" unsigned Graphics_ComputeObjectVRAMCapacity(unsigned),Graphics_ReadObjectMappingAlignmentShift(unsigned);
extern "C" void ReadGlobalAt02105AB4();
extern "C" void* Object_ReleaseGlobalResourceUnlessRetained(Context*,unsigned);
extern "C" void SetSelectedBackgroundRecordAndEnablePairedRecord(Context*,int),SpriteTable_WriteThreeByFourTileGrid(Context*,unsigned),AdvanceModulo190AndUpdateThreeEntries(Context*,unsigned),Graphics_SetSelectedScreenBrightnessAndMarkEnabled(Context*,unsigned,int,int);
extern "C" void (*data_020f2904[])(void*,int,unsigned);
extern "C" void (*data_020f28f4[])(void*);
// Original: arm9/main @ 0x020DB5EC; symbol: func_020db5ec; size: 0xF8.
extern "C" void Graphics_FlushAndUploadActiveBankData(Context* p){if(!p->active)return;unsigned size=Graphics_ComputeObjectVRAMCapacity(p->bank);unsigned shift=Graphics_ReadObjectMappingAlignmentShift(p->bank);unsigned second=(size-0xb80)>>shift,first=(size-0x800)>>shift;ReadGlobalAt02105AB4();void* data=Object_ReleaseGlobalResourceUnlessRetained(p,p->bank);SetSelectedBackgroundRecordAndEnablePairedRecord(p,0);if(p->flag)SpriteTable_WriteThreeByFourTileGrid(p,first);AdvanceModulo190AndUpdateThreeEntries(p,second);CleanInvalidateCacheRange(data,0xe0);data_020f2904[p->bank](data,0,0xe0);CleanCacheRange(data,0xe0);DMAMemsetSynchronous(3,(unsigned)data+0x20,0xc0,0x60);Graphics_SetSelectedScreenBrightnessAndMarkEnabled(p,p->bank,0,0);data_020f28f4[p->bank](p->handle);}
