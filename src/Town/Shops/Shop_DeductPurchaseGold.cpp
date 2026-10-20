#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" unsigned short* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" unsigned Shop_GetAdjustedItemPrice(char*,unsigned short*);
extern "C" void Shop_RefreshGoldDisplay(char*);
// Original: arm9/ov003 @ 0x02175924; symbol: func_ov003_02175924; size: 0x78.
// Deducts the selected quantity's cost when affordable and marks the gold display changed.
extern "C" int Shop_DeductPurchaseGold(char* self)
{
    char* inventory = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned short* item = ZoneState2754_FindPrimaryRecordByKey(
        self + 0x874, *(short*)(self + 0x103a));
    if (!item) {
        return 0;
    }
    unsigned price = Shop_GetAdjustedItemPrice(self, item);
    unsigned total = *(unsigned char*)(self + 0x103c) * price;
    unsigned gold = *(unsigned*)(inventory + 0xf6c);
    if (gold < total) {
        return 0;
    }
    *(unsigned*)(inventory + 0xf6c) = gold - total;
    Shop_RefreshGoldDisplay(self);
    *(unsigned char*)(self + 0x104f) = 1;
    return 1;
}
