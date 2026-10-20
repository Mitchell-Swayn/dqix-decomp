#include "std_library_functions.h"
extern "C" void Inventory_ClearItemStorageBinding(void*);
extern "C" void Inventory_BindItemKeysAndQuantities(void*,void*,void*,unsigned);
extern "C" void Inventory_InitializeGroupedItemStorage(void*);
extern "C" void InitializeKind63StateAndThirteenAttributeRecords(void*);
// Original: arm9/main @ 0x0208660C; symbol: func_0208660c; size: 0x16C.
extern "C" void PartyRoster_InitializeInventoryRecordsAndTransfers(char* state)
{
    memset(state + 12, -1, 0x130);
    memset(state + 0x13c, 0, 0x98);
    Inventory_ClearItemStorageBinding(state);
    Inventory_BindItemKeysAndQuantities(state, state + 12, state + 0x13c, 0x98);
    Inventory_InitializeGroupedItemStorage(state + 0x1d4);
    memset(state + 0xe10, -1, 0xbc);
    memset(state + 0xecc, 0, 0x5e);
    Inventory_ClearItemStorageBinding(state + 0xe04);
    Inventory_BindItemKeysAndQuantities(state + 0xe04, state + 0xe10, state + 0xecc, 0x5e);
    *(unsigned*)(state + 0xf68) = 0;
    *(unsigned*)(state + 0xf6c) = 0;
    *(unsigned*)(state + 0xf70) = 0;
    *(unsigned*)(state + 0xf74) = 0;
    state[0xf7c] = 0;
    for (int i = 0; i < 13; ++i) InitializeKind63StateAndThirteenAttributeRecords(state + 0xf80 + i * 0x23c);
    state[0x2c8c] = 0;
    for (int i = 0; i < 3; ++i) {
        memset(state + 0xf2c + i * 20, 0, 20);
        char* item = state + i * 20;
        item[0xf3c] = -1;
    }
    for (unsigned char i = 0; i < 7; ++i) {
        char* item = state + i;
        item[0x2c8d] = -1;
    }
    state[0x2c8d] = 3;
    *(unsigned*)(state + 0x2c94) = 0x452;
    state[0xf7d] = 0;
}
