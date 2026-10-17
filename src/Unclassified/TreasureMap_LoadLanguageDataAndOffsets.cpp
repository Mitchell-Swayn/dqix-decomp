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
extern "C" char data_020f1a9c[],data_020f1ab0[];
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" int Memory_EnsureSpaceAndAllocateThroughGlobalAllocator(void*,unsigned);
extern "C" void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();
// Original: arm9/main @ 0x020A3720; symbol: func_020a3720; size: 0x124.
extern "C" int TreasureMap_LoadLanguageDataAndOffsets() {
 GameState* state=GameState::GetInstance();
 ResourceState* resources=reinterpret_cast<ResourceState*>(GameResources_GetInstance());
 unsigned char* data=state->GetTreasureMapLanguageData();
 if(data || resources->offsets) GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();
 if(!Memory_EnsureSpaceAndAllocateThroughGlobalAllocator(&data,0x2000)) return 0;
 if(!Memory_EnsureSpaceAndAllocateThroughGlobalAllocator(&resources->offsets,0x44)) return 0;
 unsigned length=0;
 BackgroundLoader::AddLockGlobal();
 void* source=ExtractFileFromGP2(data_020f1a9c,data_020f1ab0,&length);
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
