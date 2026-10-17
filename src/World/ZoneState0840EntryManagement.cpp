#include "World/Zone3DEmbeddedState.h"

extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);

// Original: arm9/main @ 0x0209890C; symbol: _ZN13ZoneState084026IsEntryIdentifierAvailableEPKNS_5EntryE; size: 0x64.
bool ZoneState0840::IsEntryIdentifierAvailable(const Entry* entry)
{
    if (!entry->parameters6c.unknown26) return false;
    for (int i = 0; i < 30; ++i)
    {
        if (!RuntimeMemory_CompareByteRanges(entries[i].identifier, entry->identifier, 6)) return false;
    }
    return true;
}

// Original: arm9/main @ 0x02098970; symbol: _ZN13ZoneState084011RemoveEntryEPNS_5EntryE; size: 0x5C.
bool ZoneState0840::RemoveEntry(Entry* entry)
{
    int i;
    bool found = false;
    Entry* candidate;
    for (i = 0; i < 30; ++i)
    {
        candidate = &entries[i];
        if (entry == candidate)
        {
            found = true;
            break;
        }
    }
    if (!found) return false;
    --unknown_1b38;
    candidate->Reset();
    return true;
}
