#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct GameState;
struct GameResources;

extern "C" void* GameState_GetIndexList(GameState*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*, unsigned);
extern "C" void Field_RebuildActiveRosterAndCameraTarget(int,int,int,int,int);
struct RecordState { unsigned active:1; unsigned unknown:1; unsigned retained:1; unsigned remaining:29; unsigned short count; };
// Original: arm9/main @ 0x02048150; symbol: GameObject_ReviveAndRestoreHP; size: 0xD8.
// Clamps or initializes count at nested offset 4, clears all flags except bit 2,
// and optionally rebuilds active member indices when prior bit 0 is set.
extern "C" void GameObject_ReviveAndRestoreHP(char* self, int count, int notify) {
    GameState* game = (GameState*)((void*)GameState::GetInstance());
    GameResources* resources = GameResources_GetInstance();
    unsigned char* list = (unsigned char*)GameState_GetIndexList(game);
    RecordState* state = *(RecordState**)(self+0x130);
    int active = 0;
    if (*(unsigned*)state & 1) active = 1;
    int limit = *(unsigned short*)(*(char**)(self+0x134)+0x30);
    if (count > 0) {
        if (count > limit) count = limit;
        state->count = count;
    } else if (!state->count) state->count = limit;
    int retained = 0;
    RecordState* clearState = *(RecordState**)(self+0x130);
    if (*(unsigned*)clearState & 4) retained = 1;
    *(unsigned*)clearState = 0;
    if (retained) (*(RecordState**)(self+0x130))->retained = 1;
    if (active && PartyRoster_ContainsActiveObjectIndex(list, *(short*)(self+4)) && notify)
        Field_RebuildActiveRosterAndCameraTarget((int)resources, 1, 1, 1, 1);
}
