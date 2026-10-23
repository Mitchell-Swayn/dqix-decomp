#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);
extern "C" void World_ResetTemporaryZoneResourceState(void*);
extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);
extern "C" int GameState_AddItemsAndDistributeOverflow(unsigned char*,short,short,int);
struct TemporaryAllocator:SafeAllocator { TemporaryAllocator(){ResetAllocatorPointer();} };
struct TemporaryInventory { TemporaryAllocator allocator;ZoneState2754 state;ZoneState2754* source;unsigned a,b;
TemporaryInventory(){World_ResetZoneStateAndClearThreeWords((unsigned char*)this);}
};
static inline int IsGroupedItem(const ZoneSerializedRecord* item){return item->category.category<=7;}
struct Shop { unsigned char unknown[0x874];ZoneState2754 items;unsigned char gap[0x103a-0x88c];short selected;signed char quantity;unsigned char gap2[0x104f-0x103d];unsigned char flag; };
// Original: arm9/ov003 @ 0x02175CB0; symbol: Shop_AddPurchasedItemToInventory; size: 0xC8.
// Build a temporary inventory view, add the selected quantity, then reset its state.
extern "C" ARM int Shop_AddPurchasedItemToInventory(void* object,int distribute) {
Shop* shop=(Shop*)object;
shop->flag=0;
ZoneSerializedRecord* item=(ZoneSerializedRecord*)ZoneState2754_FindPrimaryRecordByKey(&shop->items,shop->selected);
if(!item)return 0;
GameState_GetIndexList(GameState::GetInstance());
{TemporaryInventory temp;
World_ResetZoneStateAndClearThreeWords((unsigned char*)&temp);
temp.source=&shop->items;
if(IsGroupedItem(item))Inventory_AddGroupedItemQuantityAndCacheResult((char*)&temp,item->key,shop->quantity);
else GameState_AddItemsAndDistributeOverflow((unsigned char*)&temp,item->key,(unsigned char)shop->quantity,distribute);
World_ResetTemporaryZoneResourceState(&temp);
}
return 0;
}
