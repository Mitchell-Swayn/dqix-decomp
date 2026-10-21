#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma scheduling off
struct Owner;
extern "C" {
void* GameState_GetIndexList(GameState* state);
void TextCanvas_ResetOtherDisplayParts(Owner* owner, unsigned index);
void Shop_CancelItemDetailLoads(void *object);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p, int key);
void Shop_RefreshSaleOwnerNames(unsigned char* self);
void TextCanvas_SetDisplayPartRefreshFlag(void* p, int key, int enabled);
void TextCanvas_SetGroupPalette(char* self, int id, unsigned char value);
void KeyRepeater_Reset(unsigned char* p);
int Shop_TestSelectionConfirmation(char* obj);
int Shop_TestSelectionCancellation(unsigned char* self);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
int GameState_CountSelectedAvailableQuantities(char *self);
extern char Main_UnknownRoleZeroInitializedStorage[];
}
namespace {
extern "C" void Shop_RefreshSaleOwnerItemPreview(void*);
}

// Original: arm9/ov003 @ 0x0217A4AC; symbol: func_ov003_0217a4ac; size: 0x2b8.
// Advances sale-owner selection: reset parts, apply the sale-mode group jump
// table, then confirm or cancel into the next shop phase.
extern "C" void Shop_AdvanceSaleOwnerSelection(unsigned char* self)
{
    GameState_GetIndexList(GameState::GetInstance());
    unsigned char phase = self[0x103f];
    Owner* owner = *(Owner**)(self + 0x89c);
    if (phase == 0) {
        *(short*)(self + 0x1014) = 0;
        *(short*)(self + 0x1016) = 0;
        TextCanvas_ResetOtherDisplayParts(owner, 0);
        self[0x103f] = self[0x103f] + 1;
        return;
    }
    if (phase == 1) {
        Shop_CancelItemDetailLoads(self);
        switch (*(unsigned*)(self + 0x1030)) {
        case 1:
            *(short*)(self + 0xffe) = 0x11;
            break;
        case 2:
            *(short*)(self + 0xffe) = 0x12;
            break;
        case 3:
            *(short*)(self + 0xffe) = 0x13;
            break;
        case 4:
            *(short*)(self + 0xffe) = 0x14;
            break;
        }
        if (*(short*)(self + 0x1010) < 0)
            *(short*)(self + 0x1010) = (short)FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(
                (unsigned char*)owner, *(short*)(self + 0xffe));
        *(short*)((char*)owner + 0x36) = *(short*)(self + 0x1010);
        Shop_RefreshSaleOwnerNames(self);
        Shop_RefreshSaleOwnerItemPreview(self);
        TextCanvas_SetDisplayPartRefreshFlag(owner, *(short*)(self + 0xffe), 0);
        TextCanvas_SetGroupPalette((char*)owner, *(short*)(self + 0xffe), 0);
        KeyRepeater_Reset(self + 0x88c);
        *(unsigned*)(self + 0xff8) = 0;
        self[0x103f] = self[0x103f] + 1;
        return;
    }
    if (phase != 2)
        return;
    *(unsigned char**)(self + 0xff8) = self + 0x1010;
    Shop_RefreshSaleOwnerItemPreview(self);
    TextCanvas_SetGroupPalette(*(char**)(self + 0x89c), 0x15, 1);
    if (Shop_TestSelectionConfirmation((char*)self) != 0) {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
        KeyRepeater_Reset(self + 0x88c);
        *(unsigned*)(self + 0xff8) = 0;
        int value = GameState_CountSelectedAvailableQuantities((char*)self);
        if (value == 0) {
            value = *(signed char*)(self + 0x1043);
            int valid = 0;
            short message = 0x13;
            if (value < 0)
                message = 0x14;
            *(short*)(self + 0x1036) = message;
            TextCanvas_ResetOtherDisplayParts(owner, valid);
            self[0x103f] = 0;
            *(unsigned short*)(self + 0x1046) |= 0x20;
            return;
        }
        value = *(signed char*)(self + 0x1043);
        int valid = 0;
        unsigned char next = 5;
        if (value >= 0)
            valid = value <= 3;
        if (valid == 0) {
            next = 6;
            TextCanvas_ResetOtherDisplayParts(owner, 0);
        }
        self[0x103e] = next;
        self[0x103f] = 0;
        TextCanvas_SetGroupPalette((char*)owner, *(short*)(self + 0xffe), 1);
        *(short*)(self + 0xffc) = *(short*)(self + 0xffe);
        *(short*)(self + 0x100e) = -1;
        self[0x103c] = 1;
        return;
    }
    if (Shop_TestSelectionCancellation(self) == 0)
        return;
    *(unsigned*)(self + 0xff8) = 0;
    TextCanvas_ResetOtherDisplayParts(owner, 0);
    self[0x103e] = 3;
    self[0x103f] = 0;
}
