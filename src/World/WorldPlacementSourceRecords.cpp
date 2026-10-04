#include "World/WorldPlacementSource.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" {
    void func_0205ec34(GameState*);
    int func_0201079c(GameState*);
}

void WorldPlacementSource::AppendRecord(Record* record)
{
    Record** link = &head;
    while (*link) link = &(*link)->next;
    *link = record;
    ++count;
}

WorldPlacementSource::Record* WorldPlacementSource::FindRecord(int index)
{
    for (Record* record = head; record; record = record->next)
        if (record->index == index) return record;
    return 0;
}

int WorldPlacementSource::GetRandomValue()
{
    if (!randomValues) return 0;
    int size = 8;
    GameState* game = GameState::GetInstance();
    func_0205ec34(game);
    if (func_0201079c(game) >= 19) size = 16;
    return randomValues[NextRandomMax(GetBTRandom(), size)];
}
