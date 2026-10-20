#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(void*,int);
extern "C" int Inventory_CountOccupiedSlots(void*);
// Original: arm9/ov003 @ 0x02179E44; symbol: func_ov003_02179e44; size: 0xF0.
// Resolves the sale owner and resets the page count for a party member or shared inventory.
// Owner modes 1..4 select display keys 17..20; other modes leave the key unspecified in the original.
extern "C" void Shop_SelectSaleOwnerAndResetPaging(char* self)
{
    char* inventory = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned ownerMode = *(unsigned*)(self + 0x1030);
    void* canvas = *(void**)(self + 0x89c);
    int group;
    switch (ownerMode) {
    case 1: group = 17; break;
    case 2: group = 18; break;
    case 3: group = 19; break;
    case 4: group = 20; break;
    }
    *(signed char*)(self + 0x1043) = -1;
    short index = *(short*)(self + 0x1010) - FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(canvas, group);
    if (*(int*)(self + 0x1030) > index) {
        *(unsigned char*)(self + 0x1043) = *(unsigned*)(self + 0x101c + index * 4);
        *(short*)(self + 0x1014) = 0;
        *(short*)(self + 0x1016) = 1;
    } else {
        int count = Inventory_CountOccupiedSlots(inventory);
        *(short*)(self + 0x1014) = 0;
        *(short*)(self + 0x1016) = (count + 7) / 8;
        if (*(short*)(self + 0x1016) == 0) {
            *(short*)(self + 0x1016) = 1;
        }
    }
}
