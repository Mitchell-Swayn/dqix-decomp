#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* Menu_FindInventoryGridByKey(void*, unsigned);
extern "C" int GameState_TestRecordWithMode65(int);
extern "C" int GetTypeSevenRowMajorIndex(void*, unsigned);
extern "C" int Menu_GetSelectedInventoryPartyMember(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" unsigned int Inventory_GetGroupItemIds(void*, unsigned);
extern "C" void* Menu_GetInventoryDetailState(void*, unsigned);
extern "C" void Graphics_SelectBackgroundStateRecord(char*, int);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0215BE9C; symbol: ApplyModeSelectedBackgroundRecord; size: 0xF8.
// Resolves a selected record from the mode-dependent actor table and applies it to a background state.
extern "C" ARM int ApplyModeSelectedBackgroundRecord(void* self) {
    void* game = _ZN9GameState11GetInstanceEv();
    unsigned char* indices = (unsigned char*)GameState_GetIndexList(game);
    if (!indices) return 0;
    void* actor = Menu_FindInventoryGridByKey(self, 0x63);
    int offset = *(short*)((char*)actor + 0x5c) << 3;
    unsigned char* table;
    if (GameState_TestRecordWithMode65((int)self)) {
        int row = GetTypeSevenRowMajorIndex(self, 0x65);
        if (row < 0) return 0;
        unsigned char* entryTable = *(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8) + row;
        unsigned selector = entryTable[0x7c];
        table = (unsigned char*)Inventory_GetGroupItemIds(indices + 0x1d4, selector);
    } else {
        int typeIndex = Menu_GetSelectedInventoryPartyMember(self);
        if (typeIndex >= 0) {
            void* object = GameState_GetObjectWithFlag100(game, typeIndex);
            if (!object) return 0;
            table = GameObject_GetLinkedIndexedState(object) + 0x454;
            offset = 0;
        } else { table = indices + 0xc; }
    }
    void* background = Menu_GetInventoryDetailState(self, 7);
    int slot = GetTypeSevenRowMajorIndex(self, 0x63);
    if (background) {
        int value = *(short*)(table + ((offset + slot) << 1));
        Graphics_SelectBackgroundStateRecord((char*)background, value);
    }
    return 0;
}
