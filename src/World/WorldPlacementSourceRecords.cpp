#include "World/WorldPlacementSource.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" {
    void ReadGlobalValueAt02108844(GameState*);
    int GameState_ReadWordAtOffset5CB0(GameState*);
}

// Original: arm9/main @ 0x0208E778; symbol: _ZN20WorldPlacementSource12AppendRecordEPNS_6RecordE; size: 0x2C.
void WorldPlacementSource::AppendRecord(Record* record)
{
    Record** link = &head;
    while (*link) link = &(*link)->next;
    *link = record;
    ++count;
}

// Original: arm9/main @ 0x0208E7A4; symbol: _ZN20WorldPlacementSource10FindRecordEi; size: 0x2C.
WorldPlacementSource::Record* WorldPlacementSource::FindRecord(int index)
{
    for (Record* record = head; record; record = record->next)
        if (record->index == index) return record;
    return 0;
}

// Original: arm9/main @ 0x0208E7D0; symbol: _ZN20WorldPlacementSource14GetRandomValueEv; size: 0x54.
int WorldPlacementSource::GetRandomValue()
{
    if (!randomValues) return 0;
    int size = 8;
    GameState* game = GameState::GetInstance();
    ReadGlobalValueAt02108844(game);
    if (GameState_ReadWordAtOffset5CB0(game) >= 19) size = 16;
    return randomValues[NextRandomMax(GetBTRandom(), size)];
}
