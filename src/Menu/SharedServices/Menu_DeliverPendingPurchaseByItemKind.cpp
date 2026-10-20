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
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13ZoneState2754C1Ev(void*);extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);extern "C" void World_ResetTemporaryZoneResourceState(void*);extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);extern "C" unsigned TextContext_GetSharedInstance();extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];extern "C" char* Menu_GetInventoryRecordSourceByKey(void*,unsigned);extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);extern "C" void* Text_LookupNameTableEntry(void*,int);extern "C" void Menu_QueueScriptEntry(void*,unsigned);extern "C" int GetTypeSevenRowMajorIndex(void*,unsigned);extern "C" char* Menu_GetInventorySlotOnCurrentPage(void*,unsigned char);extern "C" int GameState_AddItemsAndDistributeOverflow(unsigned char*,short,short,int);struct Kind{unsigned first[2];unsigned kind:4,rest:28;};
// Original: arm9/ov004 @ 0x0215E148; symbol: Resource_ApplySharedItemThroughSelectedTypeSevenEntry; size: 0x114.
extern "C" int Menu_DeliverPendingPurchaseByItemKind(void* self){if(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)&&B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),157)){_ZN9GameState11GetInstanceEv();int index=GetTypeSevenRowMajorIndex(self,91);if(index<0)return 0;char* selected=Menu_GetInventorySlotOnCurrentPage(self,(unsigned char)index);if(!selected)return 0;char* heap=Menu_GetInventoryRecordSourceByKey(self,5);if(!heap)return 0;char* record=ZoneState2754_FindPrimaryRecordByKey(heap,H(selected,0));if(!record)return 0;char temporary[56];_ZN13SafeAllocator21ResetAllocatorPointerEv(temporary);_ZN13ZoneState2754C1Ev(temporary+20);World_ResetZoneStateAndClearThreeWords((unsigned char*)temporary);World_ResetZoneStateAndClearThreeWords((unsigned char*)temporary);P(temporary,44)=heap;int ordinary;if(((Kind*)record)->kind<=7)ordinary=1;else ordinary=0;if(ordinary)Inventory_AddGroupedItemQuantityAndCacheResult(temporary,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14),S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),17));else GameState_AddItemsAndDistributeOverflow((unsigned char*)temporary,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14),B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),17),1);World_ResetTemporaryZoneResourceState(temporary);}return 0;}
