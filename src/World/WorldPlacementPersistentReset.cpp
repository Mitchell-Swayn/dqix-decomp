#include "World/WorldPlacementSource.h"
#include "World/WorldObjectInstanceList.h"
#include "GameState/GameState.h"

typedef char PlacementPersistentStateSizeCheck[
    sizeof(WorldPlacementSource::PersistentState) == 4 ? 1 : -1];
typedef char GameStatePlacementByteOffsetCheck[
    offsetof(GameState, unknownPlacementByte_5cda_) == 0x5cda ? 1 : -1];
typedef char GameStatePlacementStatesOffsetCheck[
    offsetof(GameState, placementStates_) == 0x5cdc ? 1 : -1];
typedef char GameStatePlacementStatesSizeCheck[
    sizeof(((GameState*)0)->placementStates_) == 400 ? 1 : -1];
typedef char GameStatePlacementTailOffsetCheck[
    offsetof(GameState, unk_5e6c) == 0x5e6c ? 1 : -1];
typedef char GameStatePlacementSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" void func_0208ec04(WorldObjectInstanceList*)
{
    GameState* game = GameState::GetInstance();
    WorldPlacementSource::PersistentState* state =
        game->placementStates_;
    for (int i = 0; i < 100; ++i, ++state)
    {
        if (state->available && state->flags)
        {
            state->flags = 0;
            state->unknown0 = state->unknown25 * 3;
        }
    }
}
