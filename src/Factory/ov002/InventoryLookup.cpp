#include "InventoryMenuState.h"
#include "GameState/GameState.h"

// func_020a093c binds the arrays and capacity; func_020a0b8c counts nonzero
// quantities. These descriptors and inline arrays are initialized together
// by func_0208660c, with capacities 0x98 and 0x5e respectively.
struct InventoryList {
    short* items_;
    signed char* quantities_;
    short capacity_;
    unsigned char unknown_0a_[2];
};

template <int Capacity> struct StoredInventoryList {
    InventoryList list_;
    short items_[Capacity];
    signed char quantities_[Capacity];

};

struct SharedInventoryStorage {
    StoredInventoryList<0x98> bag_;
    unsigned char unknown_01d4_[0xe04 - 0x1d4];
    StoredInventoryList<0x5e> secondary_;
};

// func_02083960 scans exactly eight signed item slots at +0x454.
struct MemberInventory {
    unsigned char unknown_000_[0x454];
    short items_[8];
};

typedef char InventoryListSizeCheck[sizeof(InventoryList) == 12 ? 1 : -1];
typedef char BagStorageSizeCheck[
    sizeof(StoredInventoryList<0x98>) == 0x1d4 ? 1 : -1];
typedef char SecondaryStorageSizeCheck[
    sizeof(StoredInventoryList<0x5e>) == 0x128 ? 1 : -1];
typedef char BagItemsOffsetCheck[
    offsetof(StoredInventoryList<0x98>, items_) == 0xc ? 1 : -1];
typedef char SecondaryOffsetCheck[
    offsetof(SharedInventoryStorage, secondary_) == 0xe04 ? 1 : -1];
typedef char SecondaryItemsOffsetCheck[
    offsetof(SharedInventoryStorage, secondary_) +
    offsetof(StoredInventoryList<0x5e>, items_) == 0xe10 ? 1 : -1];
typedef char SecondaryQuantitiesOffsetCheck[
    offsetof(SharedInventoryStorage, secondary_) +
    offsetof(StoredInventoryList<0x5e>, quantities_) == 0xecc ? 1 : -1];

extern "C" void* func_02010828(GameState*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" MemberInventory* func_02053c6c(GameObject*);
extern "C" int func_020a0b8c(InventoryList*);
extern "C" int func_02083960(MemberInventory*);

extern "C" int func_ov002_02157108(InventoryMenuState*, int owner)
{
    GameState* state = GameState::GetInstance();
    int count = 0;
    if (owner == 5) {
        SharedInventoryStorage* storage =
            static_cast<SharedInventoryStorage*>(func_02010828(state));
        count = func_020a0b8c(&storage->secondary_.list_);
    } else if (owner == 4) {
        SharedInventoryStorage* storage =
            static_cast<SharedInventoryStorage*>(func_02010828(state));
        count = func_020a0b8c(&storage->bag_.list_);
    } else {
        GameObject* member = func_0200ff1c(state, owner);
        if (member != NULL)
            count = func_02083960(func_02053c6c(member));
    }
    return count;
}

