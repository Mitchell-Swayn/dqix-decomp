#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" {
    Zone3D* Zone3D_GetMainInstance();
    void World_QueueTypeB7PlacementRecord(int, int, unsigned char, int, WorldPlacementSource::PersistentState*);
}

// Original: arm9/main @ 0x0208F048; symbol: _ZN23WorldObjectInstanceList30UpdatePersistentPlacementFlagsEv; size: 0x120.
void WorldObjectInstanceList::UpdatePersistentPlacementFlags()
{
    if (unknown0 != 98) return;
    ZoneState0840* zoneState = &Zone3D_GetMainInstance()->state_840_;
    int count = (int)zoneState->unknown_1b34 / 100 + 4;
    if (count > 14) count = 14;
    int remaining = count - 7;
    int bit;
    GameState* game = GameState::GetInstance();
    WorldPlacementSource::PersistentState* states =
        game->placementStates_;
    bit = 0;
    while (remaining > 0)
    {
        states[99].flags |= 1 << bit;
        ++bit;
        --remaining;
    }
    World_QueueTypeB7PlacementRecord(0, 0, (unsigned char)states[99].flags, 99, &states[99]);
    if (bit > 0)
    {
        bit = 0;
        count = 7;
    }
    while (count > 0)
    {
        states[98].flags |= 1 << bit;
        --count;
        ++bit;
    }
    World_QueueTypeB7PlacementRecord(0, 0, (unsigned char)states[98].flags, 98, &states[98]);
}
