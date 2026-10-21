#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct State;
struct ZoneState2754;
struct Nibble {
    unsigned low : 4;
    unsigned rest : 28;
};
struct OffsetTable {
    int values[4];
};

extern "C" {
int GetTypeSevenRowMajorIndex(void* self, unsigned key);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
int Menu_GetInventoryRecordSourceByKey(...);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
int Equipment_GetPartyRestrictionMask(int, int);
int Menu_AddPurchaseToGroupedInventoryOrChooseRecipient(void* self);
void Menu_QueueScriptEntry(State* self, unsigned value);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x216fb50; symbol: MenuRoutePurchaseByEquipmentEligibility_UnknownRoleInitializedBytes.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern int MenuRoutePurchaseByEquipmentEligibility_UnknownRoleInitializedBytes[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define S(p, o) (*(short*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x02159A2C; symbol: func_ov004_02159a2c; size: 0x148.
// Routes a selected offer: grouped inventory when every compared party index is
// restricted, otherwise a party-choice or ineligible-kind script.
extern "C" int Menu_RoutePurchaseByEquipmentEligibility(void* self)
{
    char* record;
    int scale;
    int slot;
    OffsetTable table;

    GameState::GetInstance();
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index < 0)
        return 0;
    record = (char*)Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index);
    if (!record)
        return 0;
    void* source = (void*)Menu_GetInventoryRecordSourceByKey(self, 5);
    if (!source)
        return 0;
    record = (char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)source, S(record, 0));
    if (!record)
        return 0;

    unsigned kind = ((Nibble*)(record + 8))->low;
    unsigned inRange;
    if (kind <= 7)
        inRange = 1;
    else
        inRange = 0;
    if (inRange) {
        table = *(OffsetTable*)MenuRoutePurchaseByEquipmentEligibility_UnknownRoleInitializedBytes;
        int i = 0;
        char* shared = P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8);
        scale = S(shared, 0x3a);
        goto fill_check;
    fill_loop:
        table.values[i] = *(short*)(shared + 0x32 + i * 2);
        i++;
    fill_check:
        if (i < scale)
            goto fill_loop;

        slot = 0;
        goto test_check;
    test_loop:
        if (!Equipment_GetPartyRestrictionMask((signed char)table.values[slot], (int)record))
            goto test_done;
        slot++;
    test_check:
        if (slot < scale)
            goto test_loop;
    test_done:
        if (slot == scale)
            Menu_AddPurchaseToGroupedInventoryOrChooseRecipient(self);
        else
            Menu_QueueScriptEntry((State*)self, 0x38b);
    } else {
        Menu_QueueScriptEntry((State*)self, 0x2384);
    }
    return 0;
}
