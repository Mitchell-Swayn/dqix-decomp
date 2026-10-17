#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
struct Entry {unsigned key,result;unsigned flags:4,pad:28;};
extern "C" char data_02114e20[];extern "C" void AllocatePerCountBufferAndBuildGP2State(void*,unsigned*,int);extern "C" Entry* FindSerializedPrimaryRecordByKey(void*,int);extern "C" char* GameState_GetIndexList(GameState*);extern "C" int AddPositiveItemQuantityWithinTypeGroup(void*,int,unsigned,unsigned);extern "C" void RecordNewObjectIdAndPrepareTemporaryState(void*,void*);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original: arm9/main @ 0x0207D134; symbol: func_0207d134; size: 0xCC.
extern "C" int ApplyCountToPlacementRecordAndCacheResult(char* p,unsigned key,unsigned value,...) {int created=0;int result;Entry* entry;if(!*(void**)(p+44)) {AllocatePerCountBufferAndBuildGP2State(p,&key,1);created=1;}result=0;entry=FindSerializedPrimaryRecordByKey(*(void**)(p+44),*(short*)&key);if(entry) {char* state=GameState_GetIndexList(GameState::GetInstance());result=AddPositiveItemQuantityWithinTypeGroup(state+0x1d4,*(short*)&key,value,entry->flags);if(result) {RecordNewObjectIdAndPrepareTemporaryState(p,entry);*(unsigned*)(p+48)=entry->result;}}if(created) {SignedAllocatorHeader* allocator=((SafeAllocator*)p)->GetSignedAllocator();((SafeAllocator*)p)->Destroy();Memory_FreeThroughAllocatorUnion(data_02114e20,allocator);*(void**)(p+44)=0;}return result; }
