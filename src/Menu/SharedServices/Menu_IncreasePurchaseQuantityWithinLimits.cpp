#include <globaldefs.h>
ARM
extern "C" int ZoneState2754_FindPrimaryRecordByKey(...);
extern "C" int GameState_ComputeKeyedValueDeficit(...);
extern "C" int GameState_GetIndexList(...);
extern "C" int GetTypeSevenRowMajorIndex(...);
extern "C" int Menu_RefreshPurchaseQuantityAndTotal(...);
extern "C" int InvokeEntryHandlerForStateKey(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int Menu_GetInventoryRecordSourceByKey(...);
extern "C" int Menu_GetInventorySlotOnCurrentPage(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
struct Nibble{unsigned low:4;unsigned rest:28;};
// Original: arm9/ov004 @ 0x02159888; symbol: IncreaseSharedEntryLevelWhenResourcesAndKeyCapacityAllow.
extern "C" int Menu_IncreasePurchaseQuantityWithinLimits(char*self){
int index=GetTypeSevenRowMajorIndex(self,91);if(index<0)return 0;char*entry=C(Menu_GetInventorySlotOnCurrentPage(self,(unsigned char)index));if(!entry)return 0;struct EntryBits{unsigned limit:7;unsigned cost:25;};if(B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),17)>=((EntryBits*)(entry+4))->limit)return 0;char*list=C(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()));unsigned cost=(B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),17)+1)*((EntryBits*)(entry+4))->cost;if((unsigned)W(list,3948)<cost)return 0;char*table=C(Menu_GetInventoryRecordSourceByKey(self,5));if(!table)return 0;char*record=C(ZoneState2754_FindPrimaryRecordByKey(table,S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),14)));if(!record)return 0;unsigned capacity=GameState_ComputeKeyedValueDeficit(list,S(entry,0),((Nibble*)(record+8))->low,S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),58));char*shared=P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8);if(B(shared,17)>=capacity)return 0;B(shared,17)++;InvokeEntryHandlerForStateKey(self,603,1);Menu_RefreshPurchaseQuantityAndTotal(self);return 0;
}
