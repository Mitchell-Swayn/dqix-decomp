#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <System/Memory.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma opt_common_subs off
#pragma opt_dead_assignments off
struct ResourceState { unsigned char pad[0x448c]; unsigned* offsets; };
extern "C" char TreasureMap_LoadLanguageDataAndOffsets_PathDataTmapTdataGp2[],TreasureMap_LoadLanguageDataAndOffsets_MarkupTdataLGPac[];
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void TreasureMap_FreeLanguageDataAndOffsets(SafeAllocator*);
// Original: arm9/main @ 0x020A3844; symbol: func_020a3844; size: 0x118.
extern "C" int TreasureMap_AllocateAndInitializeResourceLanguageData(SafeAllocator* allocator) {
 GameState* state=GameState::GetInstance();
 ResourceState* resources=reinterpret_cast<ResourceState*>(GameResources_GetInstance());
 if(state->GetTreasureMapLanguageData() || resources->offsets) TreasureMap_FreeLanguageDataAndOffsets(allocator);
 unsigned char* data=static_cast<unsigned char*>(allocator->Allocate(0x2000));
 resources->offsets=static_cast<unsigned*>(allocator->Allocate(0x44));
 unsigned length=0;
 BackgroundLoader::AddLockGlobal();
 void* source=Filesystem_ExtractLocalizedGp2FileToScratch(TreasureMap_LoadLanguageDataAndOffsets_PathDataTmapTdataGp2,TreasureMap_LoadLanguageDataAndOffsets_MarkupTdataLGPac,&length);
 memcpy(data,source,length);
 if(length>0x2000) DisableInterruptsAndHaltForever();
 int offset=0;
 unsigned count=offset;
 MI_CpuCopy8(data,&count,4);
 offset+=4;
 for(unsigned i=0;i<count;++i) {
  MI_CpuCopy8(data+offset,resources->offsets+i,4);
  offset+=4;
 }
 BackgroundLoader::RemoveLockGlobal();
 state->SetTreasureMapLanguageDataPtr(data);
 return 1;
}
