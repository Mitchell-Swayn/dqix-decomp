#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM

struct State;
struct E { short key; short pad; unsigned int value; };
struct T { E* data; short count; };

extern "C" {
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
unsigned MenuRecord_GetType(void*);
void* Menu_GetRecordMessageTable(void*);
unsigned TextContext_GetSharedInstance();
void* SystemState_GetGlobalFlags();
void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
int SaveData_AdvanceValidatedBankReplication(unsigned char* bank, int mode);
unsigned int MessageTextTable_FindTextById(T* p, int key);
void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
void GameState_WriteUnknownF70(GameState* state, unsigned char value);
void Menu_QueueScriptEntry(State* self, unsigned value);
// Original data: arm9/ov004 @ 0x2171034; symbol: InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage.
extern unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
}

#define P(p, o) (*(unsigned char**)((p) + (o)))

// Original: arm9/ov004 @ 0x0216DD78; symbol: func_ov004_0216dd78; size: 0x204.
// Resolves type-4 key 0x192 and type-0xb key 2, advances validated bank
// replication under the background-loader lock, and routes script or
// formatted-message recovery for each result code.
extern "C" int TitleMenu_AdvancePreviousLogRecovery(void* self)
{
    void* registry = Menu_GetDisplayRecordRegistry((State*)self);
    void* logRecord = MenuRecordList_LocateByKey((void**)registry, 0x192);
    if (!logRecord)
        return 0;
    if (MenuRecord_GetType(logRecord) != 4)
        return 0;

    T* messages = (T*)Menu_GetRecordMessageTable(logRecord);
    GameState* state = GameState::GetInstance();
    unsigned ctx = TextContext_GetSharedInstance();
    unsigned int* flags = (unsigned int*)SystemState_GetGlobalFlags();

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    int keepLockBusy = 1;
    void* choice = MenuRecordList_LocateByKey((void**)registry, 2);
    if (!choice)
        return 0;
    if (MenuRecord_GetType(choice) != 0xb)
        return 0;

    *(unsigned char*)((char*)choice + 0xc) =
        (unsigned char)(*(unsigned char*)((char*)choice + 0xc) & ~8);
    *(unsigned char*)((char*)ctx + 0x19ca) = 0;
    *(unsigned char*)((char*)ctx + 0x19af) = 0;

    int status = SaveData_AdvanceValidatedBankReplication(
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10), keepLockBusy);
    if (status == 5) {
        SystemState_ClearFlags(flags, 0x80);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        Menu_QueueScriptEntry((State*)self, 0x194);
        keepLockBusy = 0;
    } else if (status == 1) {
        SystemState_ClearFlags(flags, 0x80);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        TextWindow_StartFormattedMessage(
            (void*)ctx, MessageTextTable_FindTextById(messages, 0x5dc), 0, 0xe3);
        GameState_WriteUnknownF70(state, 0);
        keepLockBusy = 0;
    } else if (status == 2) {
        SystemState_ClearFlags(flags, 0x80);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        TextWindow_StartFormattedMessage(
            (void*)ctx, MessageTextTable_FindTextById(messages, 0x5dd), 0, 0xe3);
        GameState_WriteUnknownF70(state, 0);
        keepLockBusy = 0;
    } else if (status == 3) {
        SystemState_ClearFlags(flags, 0x80);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        Menu_QueueScriptEntry((State*)self, 0x195);
        keepLockBusy = 0;
    }

    if (keepLockBusy == 0) {
        *(unsigned char*)((char*)choice + 0xc) =
            (unsigned char)(*(unsigned char*)((char*)choice + 0xc) | 8);
    }
    BackgroundLoader::RemoveLockGlobal();
    return keepLockBusy;
}
