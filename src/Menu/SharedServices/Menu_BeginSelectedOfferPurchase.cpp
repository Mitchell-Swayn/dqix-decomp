#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off

struct State;
struct ZoneState2754;
struct EntryBits {
    unsigned limit : 7;
    unsigned cost : 25;
};
struct Nibble {
    unsigned low : 4;
    unsigned rest : 28;
};

extern "C" {
void* GameState_GetIndexList(GameState* state);
int GetTypeSevenRowMajorIndex(void* self, unsigned key);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
int Menu_GetInventoryRecordSourceByKey(...);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void* Text_LookupNameTableEntry(void* p, int id);
unsigned int TextContext_GetSharedInstance();
int GameState_ComputeKeyedValueDeficit(unsigned char* self, int key, unsigned type, int scale);
void Menu_SetActiveSelectionGrid(State* self, unsigned value);
void Menu_QueueScriptEntry(State* self, unsigned value);
int Menu_ShowPurchaseQuantityPrompt(State* self);
void* GameState_AppendValueAndSetNodeFlags(void* unused, unsigned short value, unsigned int flags);
void* Menu_FindInventoryGridByKey(void* self, unsigned index);
void* __clear(void* destination, unsigned int count);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define S(p, o) (*(short*)((char*)(p) + (o)))
#define W(p, o) (*(unsigned*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x02158DCC; symbol: func_ov004_02158dcc; size: 0x220.
// Starts purchase of the selected offer after gold and inventory-deficit checks,
// queues the matching script, and clears the inventory-grid vector when flagged.
extern "C" int Menu_BeginSelectedOfferPurchase(void* self)
{
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index < 0)
        return 0;
    char* entry = (char*)Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index);
    if (!entry)
        return 0;

    char* record = (char*)ZoneState2754_FindPrimaryRecordByKey(
        (ZoneState2754*)Menu_GetInventoryRecordSourceByKey(self, 5), S(entry, 0));
    if (!record)
        return 0;

    void* name = Text_LookupNameTableEntry(
        P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0x8c, S(record, 0x18));
    *(void**)(TextContext_GetSharedInstance() + 0x18) = name;

    if (((EntryBits*)(entry + 4))->limit == 0)
        return 0;

    unsigned char* list = (unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    int deficit = GameState_ComputeKeyedValueDeficit(
        list, S(entry, 0), ((Nibble*)(record + 8))->low,
        S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x3a));
    if (deficit == 0) {
        Menu_SetActiveSelectionGrid((State*)self, 0);
        Menu_QueueScriptEntry((State*)self, 0x236b);
        return 0;
    }

    if (W(list, 0xf6c) < ((EntryBits*)(entry + 4))->cost) {
        Menu_SetActiveSelectionGrid((State*)self, 0);
        Menu_QueueScriptEntry((State*)self, 0x2365);
        return 0;
    }

    Menu_QueueScriptEntry((State*)self, 0x5e);
    S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0xe) = S(entry, 0);
    int quantity = 1;
    B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = quantity;
    B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x12) = quantity - 2;
    B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x47) = 0;

    if (((EntryBits*)(entry + 4))->limit != 1) {
        unsigned gold = W(list, 0xf6c);
        unsigned cost = ((EntryBits*)(entry + 4))->cost;
        if (gold < cost || gold >= (cost << 1))
            goto skip_prompt;
    }
    Menu_SetActiveSelectionGrid((State*)self, 0);
    Menu_ShowPurchaseQuantityPrompt((State*)self);
skip_prompt:

    GameState_AppendValueAndSetNodeFlags(self, 0x35, 0x18);
    GameState_AppendValueAndSetNodeFlags(self, 0x34, 0x10);
    if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x31)) {
        char* grid = (char*)Menu_FindInventoryGridByKey(self, 0x5b);
        Vector3i cleared;
        __clear(&cleared, 0xc);
        Vector3i copy = cleared;
        *(Vector3i*)(grid + 0x2c) = copy;
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x31) = 0;
    }
    return 0;
}
