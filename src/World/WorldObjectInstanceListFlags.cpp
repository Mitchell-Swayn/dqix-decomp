#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" {
    Zone3D* func_02012fe4();
    void func_ov017_021d38f8(int, int, unsigned char, int, WorldPlacementSource::PersistentState*);
}

void WorldObjectInstanceList::UpdatePersistentPlacementFlags()
{
    if (unknown0 != 98) return;
    ZoneState0840* zoneState = &func_02012fe4()->state_840_;
    int count = (int)zoneState->unknown_1b34 / 100 + 4;
    if (count > 14) count = 14;
    int remaining = count - 7;
    int bit;
    GameState* game = GameState::GetInstance();
    // Observed persistent state table offset, pending a broader GameState map.
    WorldPlacementSource::PersistentState* states =
        (WorldPlacementSource::PersistentState*)((char*)game + 0x5cdc);
    bit = 0;
    while (remaining > 0)
    {
        states[99].flags |= 1 << bit;
        ++bit;
        --remaining;
    }
    func_ov017_021d38f8(0, 0, (unsigned char)states[99].flags, 99, &states[99]);
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
    func_ov017_021d38f8(0, 0, (unsigned char)states[98].flags, 98, &states[98]);
}
