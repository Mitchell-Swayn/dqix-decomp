#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
typedef unsigned int undefined4;
extern "C" {
void TextCanvas_SetGroupFrameStyleEnabled(char *p, int i, int v);
void TextCanvas_SetGroupInteriorFillSuppressed(unsigned char* p, int key, int enabled);
int TextCanvas_CreateAndConfigureDisplayPart(char* self, int index);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p, int key);
void KeyRepeater_Reset(unsigned char* p);
void Tavern_PopulateActiveMemberStorageList(void* self, int flag);
int Tavern_ProcessPartyMenuConfirmation(void* self);
int Tavern_IsPartyMenuCancelled(char* self);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
int Tavern_CountLivingPartyMembersExceptSelected(void* menu);
void Graphics_UpdateCounted224ByteDisplayRecords(char* p);
void Graphics_UpdateFourPartsInSelectedGroup(unsigned char* p);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
ARM undefined4 GameObject_GetLinkedIndexedState(int param_1);
void Tavern_ResetOtherPartyMembersFollowTrails(...);
void Tavern_StoreActiveMemberAndReturnCarriedItems(char* self);
extern char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov003 @ 0x02162BA8; symbol: func_ov003_02162ba8; size: 0x398.
// Advances tavern active-member storage: builds the party list, confirms a
// living selection, then stores that member or reports vocation restrictions.
extern "C" void Tavern_AdvanceActiveMemberStorage(unsigned char* self)
{
    GameState* game = GameState::GetInstance();
    unsigned char phase = self[0x4a4];
    unsigned char* canvas = *(unsigned char**)(self + 0x324);
    short* message = (short*)(self + 0x484);
    if (phase == 0) {
        *(short*)(self + 0x482) = -1;
        *(short*)(self + 0x488) = 0x13;
        TextCanvas_SetGroupFrameStyleEnabled((char*)canvas, 0x12, 1);
        TextCanvas_SetGroupInteriorFillSuppressed(canvas, 0x12, 1);
        TextCanvas_CreateAndConfigureDisplayPart((char*)canvas, 0x12);
        *(short*)(self + 0x48e) = (short)FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(canvas, *(short*)(self + 0x488));
        *(short*)(self + 0x474) = *(short*)(self + 0x48e);
        *(short*)(canvas + 0x36) = *(short*)(self + 0x48e);
        KeyRepeater_Reset(self + 0x308);
        *(int*)(self + 0x470) = 0;
        Tavern_PopulateActiveMemberStorageList(self, 1);
        *(int*)(self + 0x464) |= 0x580000;
        if (*(int*)(self + 0x464) & 1)
            *(int*)(self + 0x464) |= 0x800000;
        self[0x4a4] = (unsigned char)(self[0x4a4] + 1);
        return;
    }
    if (phase == 1) {
        Graphics_UpdateFourPartsInSelectedGroup(self);
        *(void**)(self + 0x470) = self + 0x48e;
        if (*(int*)(self + 0x464) & 0x1000000) {
            *(int*)(self + 0x464) |= 0x580000;
            if (*(int*)(self + 0x464) & 1)
                *(int*)(self + 0x464) |= 0x800000;
            Tavern_PopulateActiveMemberStorageList(self, 1);
        }
        if (Tavern_ProcessPartyMenuConfirmation(self) != 0) {
            int found = FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(canvas, *(short*)(self + 0x488));
            int diff = (*(short*)(self + 0x48e) - found) << 16;
            if ((int)self[0x4ad] <= (diff >> 16))
                return;
            *(short*)(self + 0x482) = (self + (diff >> 16))[0x4a9];
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            KeyRepeater_Reset(self + 0x308);
            *(int*)(self + 0x470) = 0;
            if (Tavern_CountLivingPartyMembersExceptSelected(self) == 0) {
                Graphics_UpdateCounted224ByteDisplayRecords((char*)canvas);
                *(int*)(self + 0x464) |= 0x80000;
                message[0] = 0x49;
                message[1] = 2;
                self[0x4a3] = 1;
                self[0x4a4] = 0;
                return;
            }
            Graphics_UpdateCounted224ByteDisplayRecords((char*)canvas);
            *(int*)(self + 0x464) |= 0x80000;
            self[0x4a4] = (unsigned char)(self[0x4a4] + 1);
            return;
        }
        if (Tavern_IsPartyMenuCancelled((char*)self) == 0)
            return;
        KeyRepeater_Reset(self + 0x308);
        *(int*)(self + 0x470) = 0;
        Graphics_UpdateCounted224ByteDisplayRecords((char*)canvas);
        *(int*)(self + 0x464) |= 0x80000;
        message[0] = 2;
        self[0x4a3] = 1;
        self[0x4a4] = 0;
        return;
    }
    if (phase == 2) {
        unsigned char saved = self[0x4a3];
        self[0x4a3] = 0x10;
        GameObject* object = GameState_GetObjectWithFlag100(game, *(short*)(self + 0x482));
        if (object == 0)
            return;
        int linked = (int)GameObject_GetLinkedIndexedState((int)object);
        self[0x4a3] = saved;
        int hasItems = *(short*)(linked + 0x454) > 0;
        int flags = **(int**)((char*)object + 0x130);
        if (flags & 1) {
            message[0] = 0xc;
            message[1] = 2;
            self[0x4a3] = 1;
            self[0x4a4] = 0;
        } else {
            unsigned nibble = ((unsigned)*(unsigned char*)(linked + 0x56b) << 24) >> 28;
            if (nibble == 2 || nibble == 4) {
                message[0] = 0x54;
                if (hasItems)
                    message[1] = 0xe;
                self[0x4a4] = 5;
            } else if (nibble == 3) {
                message[0] = 0x55;
                if (hasItems)
                    message[1] = 0x1f;
                self[0x4a4] = 5;
            } else {
                message[0] = 0xb;
                self[0x4a3] = 8;
                self[0x4a4] = 0;
                Tavern_ResetOtherPartyMembersFollowTrails(self);
                *(int*)(self + 0x464) |= 2;
                *(int*)(self + 0x464) |= 0x200;
            }
        }
        *(int*)(self + 0x464) |= 0x10;
        return;
    }
    if (phase != 5)
        return;
    Tavern_ResetOtherPartyMembersFollowTrails(self);
    Tavern_StoreActiveMemberAndReturnCarriedItems((char*)self);
    message[0] = 2;
    self[0x4a3] = 1;
    self[0x4a4] = 0;
}
