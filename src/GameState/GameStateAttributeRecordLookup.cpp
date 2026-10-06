#include "GameState/GameState.h"

extern "C" GameStateAttributeRecord* func_0209a594(
    GameStateAttributeTable* table, int identifier)
{
    int i;
    GameStateAttributeRecord* records = table->records_;
    if (records == NULL)
        return NULL;

    if (identifier >= 0x11f)
        return NULL;

    if (records[identifier].identifier_ == identifier)
        return &records[identifier];

    for (i = 0; i < table->count_; ++i)
    {
        if (records[i].identifier_ == identifier)
            return &records[i];
    }

    return NULL;
}
