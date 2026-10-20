#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* GameState_FindIndexedObjectWithFlag400(GameState*, int);
#pragma force_active on
// Original: arm9/ov000 @ 0x02163C0C; symbol: func_ov000_02163c0c; size: 0x74.
// Tests monster slots for species0x1fd,0x1fe,or0x308..0x30b in the presentation exception set.
extern "C" bool Combat_IsMonsterInPresentationExceptionSet(void*, int actorIndex)
{
    GameState* state = GameState::GetInstance();
    bool monster;
    if (actorIndex >= 0xc0 && actorIndex <= 0xc7) monster = true;
    else monster = false;
    if (monster) {
        GameObject* actor = GameState_FindIndexedObjectWithFlag400(state, actorIndex);
        if (actor) {
            int species = *(short*)((unsigned char*)actor + 2);
            if (species == 0x1fd || species == 0x1fe || (unsigned)(species - 0x308) <= 3) return true;
        }
    }
    return false;
}
#pragma force_active off
