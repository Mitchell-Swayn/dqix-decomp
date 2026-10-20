#include "World/WorldPlacementSource.h"
#include "GameState/GameState.h"
// Original: arm9/main @ 0x0208E894; symbol: func_0208e894; size: 0x154.
// Reads placement initialization opcode102 and sets its packed persistent state.
extern "C" int WorldPlacement_ReadPersistentStateRecord(Script::Parameter* parameters, int)
{
    int index = parameters[0].ToInt();
    int mode = parameters[2].ToInt();
    int variant = parameters[4].ToInt();
    int duration = parameters[5].ToInt();
    int value13 = parameters[6].ToInt();
    int count = parameters[7].ToInt();
    WorldPlacementSource::PersistentState* states = GameState::GetInstance()->placementStates_;
    if (variant == 8) {
        states[index].unknown0 = 0;
        states[index].count = count;
        states[index].flags = 0;
        states[index].unknown25 = duration / 30;
        states[index].unknown13 = value13;
        states[index].unknown29 = mode;
        states[index].available = 1;
    } else {
        WorldPlacementSource::Variant* variants = WorldPlacementSource::GetInstance()->variants;
        states[index].unknown0 = 0;
        states[index].count = variants[variant].slotCount;
        states[index].flags = 0;
        states[index].unknown25 = variants[variant].parameter / 30;
        states[index].unknown13 = variants[variant].unknown2;
        states[index].unknown29 = mode;
        states[index].available = 1;
    }
    return 1;
}
