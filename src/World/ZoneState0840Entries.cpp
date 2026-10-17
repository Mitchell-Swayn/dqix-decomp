#include "World/Zone3DEmbeddedState.h"

// Original: arm9/main @ 0x020984B0; symbol: _ZN13ZoneState084016ClearEntryStatesEv; size: 0x2C.
void ZoneState0840::ClearEntryStates()
{
    for (int i = 0; i < 30; ++i) entries[i].flags.state = 0;
}

// Original: arm9/main @ 0x020984DC; symbol: _ZN13ZoneState084020CollectEntriesOfKindEiPPNS_5EntryE; size: 0x70.
int ZoneState0840::CollectEntriesOfKind(int kind, Entry** output)
{
    if (!output) return 0;
    if (kind >= 11) return 0;
    int count = 0;
    for (int i = 0; i < 30; ++i)
    {
        Entry* entry = &entries[i];
        if (entry->value.value && entry->flags.kind == kind)
        {
            output[count] = entry;
            ++count;
            if (count >= 6) break;
        }
    }
    return count;
}
