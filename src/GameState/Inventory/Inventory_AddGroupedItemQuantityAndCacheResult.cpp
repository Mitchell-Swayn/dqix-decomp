#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
struct Entry {unsigned key,result;unsigned flags:4,pad:28;};
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" void AllocatePerCountBufferAndBuildGP2State(void*,unsigned*,int);extern "C" Entry* ZoneState2754_FindPrimaryRecordByKey(void*,int);extern "C" char* GameState_GetIndexList(GameState*);extern "C" int Inventory_AddItemQuantityToTypeGroup(void*,int,unsigned,unsigned);extern "C" void Inventory_LogFirstAcquisitionAndUpdateCounters(void*,void*);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original: arm9/main @ 0x0207D134; symbol: func_0207d134; size: 0xCC.
extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char* p,unsigned key,unsigned value,...) {int created=0;int result;Entry* entry;if(!*(void**)(p+44)) {AllocatePerCountBufferAndBuildGP2State(p,&key,1);created=1;}result=0;entry=ZoneState2754_FindPrimaryRecordByKey(*(void**)(p+44),*(short*)&key);if(entry) {char* state=GameState_GetIndexList(GameState::GetInstance());result=Inventory_AddItemQuantityToTypeGroup(state+0x1d4,*(short*)&key,value,entry->flags);if(result) {Inventory_LogFirstAcquisitionAndUpdateCounters(p,entry);*(unsigned*)(p+48)=entry->result;}}if(created) {SignedAllocatorHeader* allocator=((SafeAllocator*)p)->GetSignedAllocator();((SafeAllocator*)p)->Destroy();Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocator);*(void**)(p+44)=0;}return result; }
