#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
ARM

extern "C" {
void* Zone3D_GetMainInstance();
unsigned GameState_GetProgressChapter(GameState*);
unsigned GameState_ReadUnknown5cb4(GameState*);
void Script_ExecuteCodeWithGlobalContextAndResetList(unsigned char*, void*, const void*, unsigned, unsigned short, unsigned, unsigned);
extern unsigned char QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage[];
extern char QuestLoadOrdersForCurrentScenario_UnknownRoleInitializedBytes[];
}

// Original: arm9/main @ 0x02095578; symbol: func_02095578; size: 0xB4.
// Loads the order script with the current zone, progress chapter and stage.
extern "C" int Quest_LoadOrdersForCurrentScenario()
{
    GameState* state = GameState::GetInstance();
    void* zone = Zone3D_GetMainInstance();
    unsigned char* orderState = QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage;
    GameResources* resources = GameResources_GetInstance();
    BackgroundLoader::GetInstance();
    // Keep the allocator subobject address across the script-loading calls.
    SafeAllocator* context = (SafeAllocator*)((unsigned)resources +
        offsetof(GameResources, allocator_array_38) + 15 * sizeof(SafeAllocator));
    unsigned short zoneId = *(unsigned short*)zone;
    unsigned chapter = GameState_GetProgressChapter(state);
    unsigned stage = GameState_ReadUnknown5cb4(state);
    char path[64];
    unsigned size;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, QuestLoadOrdersForCurrentScenario_UnknownRoleInitializedBytes);
    void* code = LoadFileIntoMemory(path, Main_UnknownRoleZeroInitializedStorage_Variant6, &size);
    if (code) {
        Script_ExecuteCodeWithGlobalContextAndResetList(orderState, context, code, size,
                                                      zoneId, chapter, stage);
    }
    BackgroundLoader::RemoveLockGlobal();
    if (!code) return 0;
    return 1;
}
