#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* GameState_GetIndexList(void*);int PartyInventory_GetTotalItemQuantity(unsigned char*,int);void* Menu_GetInventoryRecordSourceByKey(void*,unsigned);void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void _ZN13ZoneState2754C1Ev(void*);void World_ResetZoneStateAndClearThreeWords(unsigned char*);int GameState_AddItemsAndDistributeOverflow(unsigned char*,short,short,int);void World_ResetTemporaryZoneResourceState(void*);void Menu_QueueScriptEntry(void*,unsigned);void* GameState_AppendValueAndSetNodeFlags(void*,unsigned short,unsigned);extern unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov004 @ 0x0215DA0C; symbol: Resource_ApplyPendingSharedItemAndChooseMessage; size: 0x108.
// Applies pending shared item amount using temporary allocator state and selects overflow or ordinary message.
extern "C" int Menu_DeliverPendingPurchaseToBag(void* self){int count=PartyInventory_GetTotalItemQuantity(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14));if(!P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[0x9d])return 0;void* heap=Menu_GetInventoryRecordSourceByKey(self,5);if(heap){unsigned char temporary[56];_ZN13SafeAllocator21ResetAllocatorPointerEv(temporary);_ZN13ZoneState2754C1Ev(temporary+20);World_ResetZoneStateAndClearThreeWords(temporary);World_ResetZoneStateAndClearThreeWords(temporary);P(temporary,44)=(unsigned char*)heap;GameState_AddItemsAndDistributeOverflow(temporary,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14),P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[17],1);World_ResetTemporaryZoneResourceState(temporary);P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[0x9d]=0;}if(count+P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[17]>99)Menu_QueueScriptEntry(self,0x2385);else Menu_QueueScriptEntry(self,0x38d);GameState_AppendValueAndSetNodeFlags(self,2,8);return 0;}
