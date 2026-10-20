#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13ZoneState2754C1Ev(void*);extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);extern "C" void World_ResetTemporaryZoneResourceState(void*);extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);extern "C" unsigned TextContext_GetSharedInstance();extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];extern "C" char* Menu_GetInventoryRecordSourceByKey(void*,unsigned);extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);extern "C" void* Text_LookupNameTableEntry(void*,int);extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original: arm9/ov004 @ 0x02159BCC; symbol: Resource_ResolveSharedPlacementAndDisplayOutcome; size: 0x114.
extern "C" int Menu_AddPurchaseToGroupedInventoryOrChooseRecipient(void* self){char* source=Menu_GetInventoryRecordSourceByKey(self,5);if(!source)return 0;char* record=ZoneState2754_FindPrimaryRecordByKey(source,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14));if(!record)return 0;void* found=Text_LookupNameTableEntry(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)+140,H(record,24));P((void*)TextContext_GetSharedInstance(),24)=(char*)found;S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),18)=-1;if(!B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),71)){char* heap=Menu_GetInventoryRecordSourceByKey(self,5);if(heap){char temporary[56];_ZN13SafeAllocator21ResetAllocatorPointerEv(temporary);_ZN13ZoneState2754C1Ev(temporary+20);World_ResetZoneStateAndClearThreeWords((unsigned char*)temporary);World_ResetZoneStateAndClearThreeWords((unsigned char*)temporary);P(temporary,44)=heap;Inventory_AddGroupedItemQuantityAndCacheResult(temporary,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14),S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),17));World_ResetTemporaryZoneResourceState(temporary);}Menu_QueueScriptEntry(self,0x38c);unsigned result=0;B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),157)=result;return result;}else Menu_QueueScriptEntry(self,0x2379);return 0;}
