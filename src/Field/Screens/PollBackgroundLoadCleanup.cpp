#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void Field_ReloadZoneActorsEntranceAndMonsterModels();
extern "C" void GameResources_ClearSecondaryFlags(void*, unsigned);
struct LoadTaskState { unsigned char pad[8]; unsigned pendingValue; unsigned char pad2[0x2c]; unsigned flags; };
// Original: arm9/ov017 @ 0x021B2B14; symbol: func_ov017_021b2b14; size: 0x54.
extern "C" int PollBackgroundLoadCleanup(LoadTaskState* state) {
    if (_ZN16BackgroundLoader17GetNumQueuedTasksEv(_ZN16BackgroundLoader11GetInstanceEv()) > 0) return state->pendingValue;
    void* resources = GameResources_GetInstance();
    Field_ReloadZoneActorsEntranceAndMonsterModels();
    GameResources_ClearSecondaryFlags(resources, 8);
    GameResources_ClearSecondaryFlags(resources, 0x10);
    state->flags &= ~2u;
    return 3;
}
