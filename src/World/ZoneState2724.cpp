#include "World/Zone3DEmbeddedState.h"
// Original: arm9/main @ 0x02094D00; symbol: _ZN13ZoneState27245ResetEv; size: 0x14.
void ZoneState2724::Reset()
{
    entries = 0;
    unknown_4 = 0;
    unknown_8 = 0;
}

// Original: arm9/main @ 0x02094D14; symbol: _ZN13ZoneState27248SetEntryEPKNS_5EntryEi; size: 0x48.
void ZoneState2724::SetEntry(const Entry* entry, int index)
{
    Entry* target = &entries[index];
    target->unknown_0 = entry->unknown_0;
    target->unknown_2 = entry->unknown_2;
    target->unknown_4 = entry->unknown_4;
    target->unknown_6 = entry->unknown_6;
    target->coordinates = entry->coordinates;
}

// Original: arm9/main @ 0x02094D5C; symbol: _ZN13ZoneState27248GetEntryEi; size: 0x10.
ZoneState2724::Entry* ZoneState2724::GetEntry(int index)
{
    return &entries[index];
}
