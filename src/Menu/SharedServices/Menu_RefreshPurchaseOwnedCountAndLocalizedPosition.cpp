#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_common_subs off

struct State;
struct Owner;
struct Vector {
    int x, y, z;
};
struct ValueEntry {
    virtual void V0(unsigned);
    virtual void V1(unsigned);
    virtual void V2(unsigned);
    virtual void V3(unsigned);
    virtual void V4(unsigned);
    virtual void V5(unsigned);
    virtual void V6(unsigned);
    virtual void V7(unsigned);
    virtual void V8(unsigned);
    virtual void V9(unsigned);
    virtual void V10(unsigned);
    virtual void V11(unsigned);
    virtual void V12(unsigned);
    virtual void V13(unsigned);
    virtual void V14(unsigned);
    virtual void V15(unsigned);
    virtual void V16(unsigned);
    virtual void V17(unsigned);
    virtual void V18(unsigned);
    virtual void V19(unsigned);
    virtual void V20(unsigned);
    virtual void V21(unsigned);
    virtual void V22(unsigned);
    virtual void V23(unsigned);
    virtual void V24(unsigned);
    virtual void V25(unsigned);
    virtual void V26(unsigned);
    virtual void V27(unsigned);
    virtual void V28(unsigned);
    virtual void V29(unsigned);
    virtual void V30(unsigned);
    virtual void V31(unsigned);
    virtual void V32(unsigned);
    virtual void V33(unsigned);
    virtual void V34(unsigned);
    virtual void V35(unsigned);
    virtual void V36(unsigned);
    virtual void V37(unsigned);
    virtual void V38(unsigned);
    virtual void V39(unsigned);
    virtual void V40(unsigned);
    virtual void V41(unsigned);
    virtual void V42(unsigned);
    virtual void V43(unsigned);
    virtual void V44(unsigned);
    virtual void V45(unsigned);
    virtual void V46(unsigned);
    virtual void V47(unsigned);
    virtual void V48(unsigned);
    virtual void V49(unsigned);
    virtual void V50(unsigned);
    virtual void V51(unsigned);
    virtual void V52(unsigned);
    virtual void V53(unsigned);
    virtual void V54(unsigned);
    virtual void V55(unsigned);
    virtual void V56(unsigned);
};
struct Positionable {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void SetPosition(Vector* position);
};

extern "C" {
void* GameState_GetIndexList(GameState* state);
unsigned GameState_ReadSupportedFirmwareLanguage(GameState* state);
short SumIndexedValuesAcrossPresentPartyIds(Owner* self, int index);
int GetTypeSevenRowMajorIndex(void* self, unsigned key);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
void* Menu_FindInventoryValueEntryByKey(void* self, unsigned key);
void* Menu_FindInventoryTextCanvasByKey(State* self, unsigned id);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
unsigned MenuRecord_GetType(void* self);
void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
}

// Original: arm9/ov004 @ 0x0215D384; symbol: func_ov004_0215d384; size: 0x1b0.
// Writes the party-owned count for the selected offer into value entry 0x1dc
// and repositions type-8 record 0x1dd from the firmware language.
extern "C" int Menu_RefreshPurchaseOwnedCountAndLocalizedPosition(void* self)
{
    GameState* state = GameState::GetInstance();
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index < 0)
        return 0;
    char* slot = (char*)Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index);
    if (!slot)
        return 0;
    ValueEntry* value = (ValueEntry*)Menu_FindInventoryValueEntryByKey(self, 0x1dc);
    if (!value)
        return 0;
    value->V56((unsigned)SumIndexedValuesAcrossPresentPartyIds(
        (Owner*)GameState_GetIndexList(state), *(short*)slot));
    void* canvas = Menu_FindInventoryTextCanvasByKey((State*)self, 0x1b);
    if (canvas)
        MenuTextCanvas_RefreshConfiguredFrameAndContents(canvas, self);

    void* record = MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x1dd);
    if (!record)
        return 0;
    if (MenuRecord_GetType(record) != 8)
        return 0;

    Vector position;
    position.y = 0x4000;
    position.z = 0;
    switch (GameState_ReadSupportedFirmwareLanguage(state)) {
    case 0:
        break;
    case 1:
        position.x = 0x14000;
        ((Positionable*)record)->SetPosition(&position);
        break;
    case 2:
        position.x = 0xe000;
        ((Positionable*)record)->SetPosition(&position);
        break;
    case 3:
        position.x = 0xb000;
        ((Positionable*)record)->SetPosition(&position);
        break;
    case 4:
        position.x = 0x6000;
        ((Positionable*)record)->SetPosition(&position);
        break;
    case 5:
        position.x = 0x9000;
        ((Positionable*)record)->SetPosition(&position);
        break;
    }
    return 0;
}
