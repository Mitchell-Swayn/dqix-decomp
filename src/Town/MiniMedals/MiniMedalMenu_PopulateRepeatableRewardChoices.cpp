#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct State;
struct Owner;
struct ZoneState2754;

extern "C" {
void* GameState_GetIndexList(GameState* state);
short SumIndexedValuesAcrossPresentPartyIds(Owner* self, int index);
void NumericRecord_SetValueAndDisplayModeByKey(void* self, unsigned short key, void* first, void* second);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
unsigned MenuRecord_GetType(void* self);
int MiniMedalMenu_GetPlacementState(void* self, unsigned short id);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
// Original data: arm9/ov004 @ 0x216fff8; symbol: MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes.
extern char MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes[];
// Original data: arm9/ov004 @ 0x216fffa; symbol: MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2.
extern char MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2[];
}

#define S(p, o) (*(short*)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define W(p, o) (*(int*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x021680CC; symbol: func_ov004_021680cc; size: 0x178.
// Fills six repeatable mini-medal reward slots from placement state and refreshes
// the two type-6 summary canvases.
extern "C" int MiniMedalMenu_PopulateRepeatableRewardChoices(void* self)
{
    short total = SumIndexedValuesAcrossPresentPartyIds(
        (Owner*)GameState_GetIndexList(GameState::GetInstance()), 0x5617);
    NumericRecord_SetValueAndDisplayModeByKey(self, 0x2b, (void*)total, (void*)0xf);

    void* registry = Menu_GetDisplayRecordRegistry((State*)self);
    void* canvas12 = MenuRecordList_LocateByKey((void**)registry, 0xc);
    if (!canvas12)
        return 0;
    if (MenuRecord_GetType(canvas12) != 6)
        return 0;
    void* canvas13 = MenuRecordList_LocateByKey((void**)registry, 0xd);
    if (!canvas13)
        return 0;
    if (MenuRecord_GetType(canvas13) != 6)
        return 0;

    for (int i = 0; i < 6; ++i) {
        void* slot = ((void*(*)(void**, int))MenuRecordList_LocateByKey)((void**)registry, 0x15 + i);
        if (!slot)
            continue;
        if (MenuRecord_GetType(slot) != 8)
            continue;
        short item = S(MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2, i * 4);
        short shown = S(MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes, i * 4);
        int placement = MiniMedalMenu_GetPlacementState(self, 5);
        if (!placement)
            continue;
        W(slot, 0x20) = 0;
        B(slot, 0xc) = (unsigned char)(B(slot, 0xc) | 8);
        char* record = (char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)placement, item);
        if (!record)
            continue;
        W(slot, 0x20) = W(record, 4);
        B(slot, 0xc) = (unsigned char)(B(slot, 0xc) & ~8);
        ((void(*)(void*, unsigned, void*, void*))NumericRecord_SetValueAndDisplayModeByKey)(
            self, 0x21 + i, (void*)shown, (void*)0xf);
    }

    *(unsigned short*)((char*)canvas12 + 0x104) = 0;
    *(unsigned short*)((char*)canvas12 + 0x106) = 0;
    MenuTextCanvas_RefreshConfiguredFrameAndContents(canvas12, self);
    *(unsigned short*)((char*)canvas13 + 0x104) = 0;
    *(unsigned short*)((char*)canvas13 + 0x106) = 0;
    MenuTextCanvas_RefreshConfiguredFrameAndContents(canvas13, self);
    return 0;
}
