#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" unsigned char Inventory_MapShopCategoryToGroup(unsigned);
extern "C" int Inventory_GetNthPositiveItemId(void*,int,int);
// Original: arm9/ov003 @ 0x02175F20; symbol: func_ov003_02175f20; size: 0x70.
// Resolves the selected category and five-column page position to a grouped inventory item.
extern "C" int Shop_GetSelectedGroupedInventoryItem(char* self)
{
    char* inventory = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    short category = *(short*)(self + 0x1012) - 0x11e;
    int group = Inventory_MapShopCategoryToGroup(category);
    short entry = (short)(*(short*)(self + 0x100e) - 0x127);
    short index = entry;
    index += *(short*)(self + 0x1014) * 5;
    return Inventory_GetNthPositiveItemId(inventory + 0x1d4, group, index);
}
