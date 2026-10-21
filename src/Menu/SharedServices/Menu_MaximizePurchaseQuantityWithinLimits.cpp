#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct EntryBits {
    unsigned limit : 7;
    unsigned cost : 25;
};
struct Nibble {
    unsigned low : 4;
    unsigned rest : 28;
};
struct ZoneState2754;

extern "C" {
void* GameState_GetIndexList(GameState* state);
int GetTypeSevenRowMajorIndex(void* self, unsigned key);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
int Menu_GetInventoryRecordSourceByKey(...);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
int GameState_ComputeKeyedValueDeficit(unsigned char* self, int key, unsigned type, int scale);
int Menu_RefreshPurchaseQuantityAndTotal(void* self);
void InvokeEntryHandlerForStateKey(void* self, unsigned key, unsigned value);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define S(p, o) (*(short*)((char*)(p) + (o)))
#define W(p, o) (*(unsigned*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x0215C50C; symbol: func_ov004_0215c50c; size: 0x178.
// Raises the shared purchase quantity to the largest value allowed by the
// entry limit, current gold, and keyed inventory deficit, then refreshes.
extern "C" int Menu_MaximizePurchaseQuantityWithinLimits(void* self)
{
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index < 0)
        return 0;
    char* entry = (char*)Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index);
    if (!entry)
        return 0;

    unsigned char previous = B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11);
    B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = ((EntryBits*)(entry + 4))->limit;

    unsigned char* list = (unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    unsigned gold = W(list, 0xf6c);
    unsigned cost = ((EntryBits*)(entry + 4))->cost;
    unsigned quantity = B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11);
    if (gold < quantity * cost) {
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = (unsigned char)(gold / cost);
        if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) < 1)
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = 1;
    }

    void* table = (void*)Menu_GetInventoryRecordSourceByKey(self, 5);
    if (!table)
        return 0;
    char* record = (char*)ZoneState2754_FindPrimaryRecordByKey(
        (ZoneState2754*)table, S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0xe));
    if (!record)
        return 0;

    int deficit = GameState_ComputeKeyedValueDeficit(
        list, S(entry, 0), ((Nibble*)(record + 8))->low,
        S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x3a));
    if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) >= (unsigned)deficit) {
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = (unsigned char)deficit;
        if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) < 1)
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = 1;
    }

    if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) == 0)
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11) = 1;

    if (previous < B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11))
        InvokeEntryHandlerForStateKey(self, 0x25b, 1);
    Menu_RefreshPurchaseQuantityAndTotal(self);
    return 0;
}
