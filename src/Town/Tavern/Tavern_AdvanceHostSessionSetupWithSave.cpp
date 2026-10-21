#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM
extern "C" {
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(unsigned int* word, unsigned int mask);
void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
void* NavigationMessage_GetGlobalInstance();
struct State;
void NavigationMessage_ResetAndEnable(State* p);
void Graphics_UpdateCounted224ByteDisplayRecords(char* p);
void Tavern_OpenConfirmationOptions(char* p);
int Tavern_PollConfirmationOptions(unsigned char* self);
void SaveData_ResetTransferProgress(unsigned char* p);
int SaveData_AdvanceStagedSaveWrite(int, int, int, int);
struct Entry {
    unsigned int a, b;
    unsigned short key;
    unsigned char rest[14];
};
struct List {
    Entry* entries;
    unsigned short count;
};
Entry* SpriteAnimation_FindTrackByKey(List* list, unsigned int key);
void Network_ResetConnectionPoolsAndRefreshPartySlots(void);
struct Object {
    unsigned char pad[0xc1];
};
void GameObject_DisableMovementInput(Object* p, int reset);
extern char Main_UnknownRoleZeroInitializedStorage_Variant6[];
}

// Original: arm9/ov003 @ 0x02165278; symbol: func_ov003_02165278; size: 0x2b4.
// Advances host-session setup phases 0x0b-0x12: confirmation, queued-task wait,
// staged save write, network reset and a second confirmation.
extern "C" void Tavern_AdvanceHostSessionSetupWithSave(unsigned char* self)
{
    unsigned int* flags = (unsigned int*)SystemState_GetGlobalFlags();
    unsigned char* nav = (unsigned char*)NavigationMessage_GetGlobalInstance();
    char* records = *(char**)(self + 0x324);
    unsigned char phase = self[0x4a4];
    if (phase == 0xb) {
        *(short*)(self + 0x484) = 0x19;
        self[0x4a4] = self[0x4a4] + 1;
        return;
    }
    if (phase == 0xc) {
        Tavern_OpenConfirmationOptions((char*)self);
        self[0x4a4] = self[0x4a4] + 1;
        return;
    }
    if (phase == 0xd) {
        int choice = Tavern_PollConfirmationOptions(self);
        if (choice != -1) {
            if (choice != 1)
                return;
            Graphics_UpdateCounted224ByteDisplayRecords(records);
            *(short*)(self + 0x484) = 0x1a;
            self[0x4a4] = self[0x4a4] + 1;
            nav[0x3c9] = (unsigned char)(nav[0x3c9] & ~1);
            return;
        }
        *(short*)(self + 0x488) = -1;
        *(short*)(self + 0x484) = 0x3b;
        *(short*)(self + 0x486) = 1;
        Graphics_UpdateCounted224ByteDisplayRecords(records);
        self[0x4a3] = 0xa;
        self[0x4a4] = 0;
        return;
    }
    if (phase == 0xe) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() != 0)
            return;
        SystemState_SetFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        SaveData_ResetTransferProgress(self + 0x4b4);
        self[0x4a4] = self[0x4a4] + 1;
        return;
    }
    if (phase == 0xf) {
        *(unsigned*)(self + 0x464) |= 0x2000000;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (SaveData_AdvanceStagedSaveWrite(
                (int)(self + 0x4b4),
                (int)Main_UnknownRoleZeroInitializedStorage_Variant6,
                0xa,
                0) == 1) {
            Entry* track = SpriteAnimation_FindTrackByKey(*(List**)(self + 0x38c), 0);
            if (track != 0)
                *((unsigned char*)track + 0x15) = (unsigned char)(*((unsigned char*)track + 0x15) | 8);
            track = SpriteAnimation_FindTrackByKey(*(List**)(self + 0x38c), 1);
            if (track != 0)
                *((unsigned char*)track + 0x15) = (unsigned char)(*((unsigned char*)track + 0x15) & ~8);
            *(unsigned*)(self + 0x464) &= ~0x2000000u;
            *(short*)(self + 0x484) = 0x30;
            self[0x4a4] = self[0x4a4] + 1;
            SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        }
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (phase == 0x10) {
        Network_ResetConnectionPoolsAndRefreshPartySlots();
        NavigationMessage_ResetAndEnable((State*)nav);
        SystemState_ClearFlags(flags, 0x20);
        *(short*)(self + 0x484) = 0x1b;
        self[0x4a4] = self[0x4a4] + 1;
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        if (protagonist == 0)
            return;
        GameObject_DisableMovementInput((Object*)protagonist, 1);
        return;
    }
    if (phase == 0x11) {
        Tavern_OpenConfirmationOptions((char*)self);
        self[0x4a4] = self[0x4a4] + 1;
        return;
    }
    if (phase != 0x12)
        return;
    int choice = Tavern_PollConfirmationOptions(self);
    if (choice != -1) {
        if (choice != 1)
            return;
        *(short*)(self + 0x484) = 0x1c;
        self[0x4a3] = 0x10;
        self[0x4a4] = 0;
        return;
    }
    *(short*)(self + 0x484) = 0x1d;
    self[0x4a3] = 0x10;
    self[0x4a4] = 0;
}
