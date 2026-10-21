#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM

struct State;

extern "C" {
void GameState_SetUnk4Element0(GameState* state, unsigned char value);
int SaveData_AdvanceValidatedBankReplication(unsigned char* bank, int mode);
void* SystemState_GetGlobalFlags();
void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
unsigned TextContext_GetSharedInstance();
void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);
void Graphics_ClearAndStageSharedBuffers(char* p);
void* Menu_FindTextCanvasWidgetByKey(void* self, unsigned short key);
void MenuTextCanvas_SetLabelPalettePair(unsigned char* p, unsigned short a, unsigned short b);
void Menu_QueueScriptEntry(State* self, unsigned value);
// Original data: arm9/ov004 @ 0x2171034; symbol: InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage.
extern unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
}

#define B(p, o) ((p)[o])
#define P(p, o) (*(unsigned char**)((p) + (o)))

// Original: arm9/ov004 @ 0x0216E258; symbol: func_ov004_0216e258; size: 0x1a4.
// Advances validated backup-bank replication under the background-loader lock
// and queues the matching title-menu script for each result code.
extern "C" int TitleMenu_AdvanceBackupCreation(void* self)
{
    GameState* state = GameState::GetInstance();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int status = SaveData_AdvanceValidatedBankReplication(
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10), 0);
    int keepLockBusy = 1;
    if (status == 5) {
        GameState_SetUnk4Element0(state, 5);
        SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        B(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 2) = 0;
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        Menu_QueueScriptEntry((State*)self, 0x3e7);
        keepLockBusy = 0;
    } else if (status == 1) {
        unsigned ctx = TextContext_GetSharedInstance();
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)ctx);
        Graphics_ClearAndStageSharedBuffers((char*)ctx);
        SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        MenuTextCanvas_SetLabelPalettePair(
            (unsigned char*)Menu_FindTextCanvasWidgetByKey(self, 0xd4), 0, 7);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        Menu_QueueScriptEntry((State*)self, 0x1f4);
        keepLockBusy = 0;
    } else if (status == 2) {
        unsigned ctx = TextContext_GetSharedInstance();
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)ctx);
        Graphics_ClearAndStageSharedBuffers((char*)ctx);
        SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        MenuTextCanvas_SetLabelPalettePair(
            (unsigned char*)Menu_FindTextCanvasWidgetByKey(self, 0xd4), 0, 7);
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        Menu_QueueScriptEntry((State*)self, 0x1f5);
        keepLockBusy = 0;
    } else if (status == 3) {
        unsigned ctx = TextContext_GetSharedInstance();
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)ctx);
        Graphics_ClearAndStageSharedBuffers((char*)ctx);
        B(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 3) = 4;
        P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage, 0x10)[1] = 0;
        SystemState_ClearFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x80);
        Menu_QueueScriptEntry((State*)self, 0x190);
        keepLockBusy = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    return keepLockBusy;
}
