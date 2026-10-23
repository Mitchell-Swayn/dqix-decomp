#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
ARM

struct Owner;
extern "C" {
unsigned GameState_GetProgressChapter(GameState*);
unsigned GameState_ReadUnknown5cb4(GameState*);
void Script_ExecuteCodeAndDispatchResult(Owner*, void*, const void*, unsigned, unsigned, unsigned, unsigned);
void* Quest_GetGlobalOrderState();
// The unreconstructed callee consumes no incoming register; its return is ignored here.
int Quest_LoadOrdersForCurrentScenario();
extern Owner ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage;
extern char Script_LoadAndExecuteZoneTriggers_PathDataScenarioTriggerSBin[];
}

// Original: arm9/main @ 0x0206461C; symbol: func_0206461c; size: 0xE8.
// Clears trigger lists, loads the zone-name trigger script, then refreshes quest orders.
extern "C" int Script_LoadAndExecuteZoneTriggers(void* state, void* zone)
{
    GameState* game = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    Owner* triggerState = &ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage;
    // Integer address arithmetic retains the allocator subobject across the calls below.
    SafeAllocator* allocator = (SafeAllocator*)((unsigned)GameResources_GetInstance()+offsetof(GameResources,allocator_array_38)+15*sizeof(SafeAllocator));
    unsigned size = 0;
    unsigned chapter = GameState_GetProgressChapter(game);
    unsigned stage = GameState_ReadUnknown5cb4(game);
    allocator->Reset();
    *(unsigned*)((char*)state + 0x47c) = 0;
    *(unsigned*)((char*)state + 0x494) = 0;
    char suffix[4];
    char path[64];
    memcpy(suffix, (char*)zone + 5, 3);
    suffix[3] = 0;
    if (suffix[0] == 'F') suffix[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, Script_LoadAndExecuteZoneTriggers_PathDataScenarioTriggerSBin, suffix);
    void* code = LoadFileIntoMemory(path, Main_UnknownRoleZeroInitializedStorage_Variant6, &size);
    if (code) {
        Script_ExecuteCodeAndDispatchResult(triggerState, allocator, code, size,
                                           *(unsigned short*)zone, chapter, stage);
    }
    BackgroundLoader::RemoveLockGlobal();
    Quest_GetGlobalOrderState();
    Quest_LoadOrdersForCurrentScenario();
    return 1;
}
