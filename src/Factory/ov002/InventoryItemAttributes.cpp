#include "InventoryMenuState.h"
#include "World/ZoneRecordLookup.h"

extern "C" int GetInventoryItemByID(InventoryMenuState*, int, int);

// The same 32-byte serialized records are searched by func_020dedd0.
// This item-table view splits the observed two-bit field from bits 14..15;
// its gameplay name and the other attributes remain unresolved.
struct InventoryItemRecord {
    unsigned int unknown_00_[2];
    unsigned int unknownLow_08_ : 14;
    unsigned int menuAttribute_ : 2;
    unsigned int unknownHigh_08_ : 16;
    unsigned int unknown_0c_[3];
    short key_;
    unsigned char unknown_1a_[6];
};

typedef char InventoryItemRecordSizeCheck[
    sizeof(InventoryItemRecord) == sizeof(ZoneSerializedRecord) ? 1 : -1];
typedef char InventoryItemRecordKeyOffsetCheck[
    offsetof(InventoryItemRecord, key_) == 0x18 ? 1 : -1];


extern "C" int func_ov002_02157500(InventoryMenuState* menu, int slot, int owner)
{
    int item = GetInventoryItemByID(menu, slot, owner);
    if (item < 0)
        return 0;
    InventoryItemRecord* record = (InventoryItemRecord*)func_020dedd0(&menu->itemTable_, item);
    if (record != NULL)
        return record->menuAttribute_;
    return 0;
}
