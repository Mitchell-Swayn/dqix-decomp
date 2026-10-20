#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void AllocatePerCountBufferAndBuildGP2State(void*,unsigned*,int);extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_GetIndexList(void*);extern "C" int Inventory_AddItemCountWithNinetyNineLimit(void*,int,unsigned);extern "C" void Inventory_LogFirstAcquisitionAndUpdateCounters(void*,void*);extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void _ZN13SafeAllocator7DestroyEv(void*);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x0207D200; symbol: func_0207d200; size: 0xC4.
extern "C" int Inventory_AddSpecialItemQuantityAndCacheResult(char* p,unsigned key,unsigned value,...){int created=0;if(!*(void**)(p+44)){AllocatePerCountBufferAndBuildGP2State(p,&key,1);created=1;}int result=0;char* entry=ZoneState2754_FindPrimaryRecordByKey(*(void**)(p+44),*(short*)&key);if(entry){char* state=GameState_GetIndexList(_ZN9GameState11GetInstanceEv());result=Inventory_AddItemCountWithNinetyNineLimit(state+3588,*(short*)&key,value);if(result){Inventory_LogFirstAcquisitionAndUpdateCounters(p,entry);*(unsigned*)(p+48)=*(unsigned*)(entry+4);}}if(created){void* allocator=_ZNK13SafeAllocator18GetSignedAllocatorEv(p);_ZN13SafeAllocator7DestroyEv(p);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocator);*(void**)(p+44)=0;}return result;}
