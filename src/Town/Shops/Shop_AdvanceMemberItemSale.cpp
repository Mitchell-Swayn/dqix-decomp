#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
ARM
#pragma scheduling off
#pragma opt_common_subs off
#pragma opt_optimizecontrolflow off
struct Owner;
extern "C" {
void* GameState_GetIndexList(GameState* state);
void TextCanvas_ResetOtherDisplayParts(Owner* owner, unsigned index);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p, int key);
void Shop_RefreshSaleOwnerNames(unsigned char* self);
void TextCanvas_SetGroupPalette(char* self, int id, unsigned char value);
void KeyRepeater_Reset(unsigned char* p);
int Shop_TestSelectionConfirmation(char* obj);
int Shop_TestSelectionCancellation(unsigned char* self);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
void Shop_LoadSelectedItemDetailsOnce(char* self);
int GameState_AddCappedRecordValue(unsigned char* self);
int Shop_RemoveSoldItemFromOwner(char* self);
void Graphics_ResetDisplaySelectionAndLinkedOwner(unsigned char* p);
int Graphics_ProcessSelectionConfirmationAndReset(unsigned char* p);
int GameState_CheckObjectCapacity(unsigned char* object, int useObjectTotal);
void GameState_StorePartyGroupTableHalfword(unsigned char* state);
void Graphics_SelectBackgroundStateRecord(char* self, int value);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
extern char Main_UnknownRoleZeroInitializedStorage[];
}
namespace {
extern "C" void Shop_RefreshSaleOwnerItemPreview(void*);
}

// Original: arm9/ov003 @ 0x0217A764; symbol: func_ov003_0217a764; size: 0x3D0.
// Advances member-item sale: refreshes owner names/preview, then confirms a
// sale through capacity, kind, and confirmation/reset phases.
extern "C" void Shop_AdvanceMemberItemSale(unsigned char* self)
{
    GameState_GetIndexList(GameState::GetInstance());
    unsigned char phase = self[0x103f];
    Owner* owner = *(Owner**)(self + 0x89c);
    if (phase == 0) {
        int group = 0x11;
        switch (*(unsigned*)(self + 0x1030)) {
        case 2:
            group = 0x12;
            break;
        case 3:
            group = 0x13;
            break;
        case 4:
            group = 0x14;
            break;
        }
        Shop_RefreshSaleOwnerNames(self);
        Shop_RefreshSaleOwnerItemPreview(self);
        *(short*)((char*)owner + 0x36) = *(short*)(self + 0x1010);
        TextCanvas_SetGroupPalette((char*)owner, group, 1);
        *(short*)(self + 0xffc) = *(short*)(self + 0xffe);
        *(short*)(self + 0xffe) = 0x15;
        if (*(short*)(self + 0x100e) < 0)
            *(short*)(self + 0x100e) = (short)FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(
                (unsigned char*)owner, *(short*)(self + 0xffe));
        *(short*)((char*)owner + 0x36) = *(short*)(self + 0x100e);
        KeyRepeater_Reset(self + 0x8c + 0x800);
        *(unsigned*)(self + 0xff8) = 0;
        self[0x103f] = 1;
        GameState_StorePartyGroupTableHalfword(self);
        Shop_LoadSelectedItemDetailsOnce((char*)self);
        return;
    }
    if (phase == 1) {
        *(unsigned char**)(self + 0xff8) = self + 0xe + 0x1000;
        GameState_StorePartyGroupTableHalfword(self);
        Graphics_SelectBackgroundStateRecord((char*)(self + 0x3c), *(short*)(self + 0x103a));
        if (Shop_TestSelectionConfirmation((char*)self) != 0) {
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            KeyRepeater_Reset(self + 0x8c + 0x800);
            *(unsigned*)(self + 0xff8) = 0;
            *(void**)(self + 8) = ZoneState2754_FindPrimaryRecordByKey(
                (ZoneState2754*)(self + 0x74 + 0x800), *(short*)(self + 0x103a));
            if (*(void**)(self + 8) == 0)
                return;
            if (GameState_CheckObjectCapacity((unsigned char*)*(void**)(self + 8), 0) == 2) {
                TextCanvas_ResetOtherDisplayParts(owner, 0);
                *(short*)(self + 0x1036) = 0x1c;
                self[0x103e] = 1;
                self[0x103f] = 0;
                *(unsigned short*)(self + 0x1046) |= 0x2000;
                return;
            }
            TextCanvas_ResetOtherDisplayParts(owner, 0);
            short message = -1;
            unsigned char next = 0;
            unsigned kind = (*(unsigned*)((char*)*(void**)(self + 8) + 8) << 0x12) >> 0x1e;
            switch (kind) {
            case 0:
                *(unsigned short*)(self + 0x1046) |= 0x20;
                message = 0x12;
                break;
            case 1:
                message = 0xd;
                next = 4;
                break;
            case 2:
                message = 0x11;
                next = 2;
                break;
            }
            *(short*)(self + 0x1036) = message;
            self[0x103f] = next;
            unsigned short* flags = (unsigned short*)(self + 0x46 + 0x1000);
            *flags |= 0x2000;
            kind = (*(unsigned*)((char*)*(void**)(self + 8) + 8) << 0x12) >> 0x1e;
            if (kind == 0)
                *flags &= ~0x2000;
            return;
        }
        if (Shop_TestSelectionCancellation(self) == 0)
            return;
        KeyRepeater_Reset(self + 0x8c + 0x800);
        *(unsigned*)(self + 0xff8) = 0;
        self[0x103e] = 4;
        self[0x103f] = 1;
        *(unsigned short*)(self + 0x1046) |= 0x2000;
        return;
    }
    if (phase == 2) {
        Graphics_ResetDisplaySelectionAndLinkedOwner(self);
        self[0x103f] = 3;
        return;
    }
    if (phase == 3) {
        int result = Graphics_ProcessSelectionConfirmationAndReset(self);
        if (result != -1) {
            if (result != 1)
                return;
            *(short*)(self + 0x1036) = 0x10;
            self[0x103f] = 4;
            return;
        }
        *(short*)(self + 0x1036) = 0x30;
        self[0x103f] = 0;
        *(unsigned short*)(self + 0x1046) |= 0x20;
        return;
    }
    if (phase == 4) {
        Graphics_ResetDisplaySelectionAndLinkedOwner(self);
        self[0x103f] = 5;
        return;
    }
    if (phase != 5)
        return;
    int result = Graphics_ProcessSelectionConfirmationAndReset(self);
    if (result != -1) {
        if (result != 1)
            return;
        GameState_AddCappedRecordValue(self);
        Shop_RemoveSoldItemFromOwner((char*)self);
        *(short*)(self + 0x1036) = 0xe;
        self[0x103e] = 4;
        self[0x103f] = 1;
        *(unsigned short*)(self + 0x1046) |= 0x20;
        return;
    }
    *(short*)(self + 0x1036) = 0x30;
    self[0x103e] = 5;
    self[0x103f] = 0;
    *(unsigned short*)(self + 0x1046) |= 0x20;
}
