#include "InventoryMenuState.h"

// Partial inventory-menu state. The initializer at 0x0215505c clears five
// owner slots, copies party indices, and appends owner 4 (the shared bag).
// It also builds the signed-byte list from party members whose +0x1c4
// field is zero. The meaning of that eligibility field remains unresolved.
extern "C" void func_ov002_02157424(InventoryMenuState*, int*);
extern "C" void func_ov002_02157480(InventoryMenuState*, int*);

extern "C" int func_ov002_021573f8(InventoryMenuState* menu, int index)
{
    int owners[7];
    if (index < 0)
        return -1;
    func_ov002_02157424(menu, owners);
    return owners[index];
}

extern "C" void func_ov002_02157424(InventoryMenuState* menu, int* owners)
{
    if (owners == NULL)
        return;
    for (int i = 0; i < 7; ++i)
        owners[i] = -1;
    owners[0] = 4;
    for (int i = 0; i < menu->ownerCount_; ++i)
        owners[i + 1] = menu->owners_[i];
}

extern "C" void func_ov002_02157480(InventoryMenuState* menu, int* members)
{
    if (members == NULL)
        return;
    for (int i = 0; i < 4; ++i)
        members[i] = -1;
    for (int i = 0; i < menu->availableMemberCount_; ++i)
        members[i] = menu->availableMembers_[i];
}

extern "C" int func_ov002_021574d4(InventoryMenuState* menu, int index)
{
    int members[4];
    if (index < 0)
        return -1;
    func_ov002_02157480(menu, members);
    return members[index];
}
