#include "World/WorldPlacementSource.h"
#include "World/WorldObjectInstanceList.h"
#include "GameState/GameState.h"

extern "C" void func_0208ec04(WorldObjectInstanceList*)
{
    GameState* game = GameState::GetInstance();
    WorldPlacementSource::PersistentState* state =
        (WorldPlacementSource::PersistentState*)((char*)game + 0x5cdc);
    for (int i = 0; i < 100; ++i, ++state)
    {
        if (state->available && state->flags)
        {
            state->flags = 0;
            state->unknown0 = state->unknown25 * 3;
        }
    }
}
