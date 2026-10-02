#include "World/Zone3DEmbeddedState.h"
void ZoneState2724::Reset()
{
    entries = 0;
    unknown_4 = 0;
    unknown_8 = 0;
}

void ZoneState2724::SetEntry(const Entry* entry, int index)
{
    Entry* target = &entries[index];
    target->unknown_0 = entry->unknown_0;
    target->unknown_2 = entry->unknown_2;
    target->unknown_4 = entry->unknown_4;
    target->unknown_6 = entry->unknown_6;
    target->coordinates = entry->coordinates;
}

ZoneState2724::Entry* ZoneState2724::GetEntry(int index)
{
    return &entries[index];
}
