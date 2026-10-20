#include "World/Zone3DEmbeddedState.h"

extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);

// Original: arm9/main @ 0x0209854C; symbol: _ZN13ZoneState084016FindEntryByStateEi; size: 0x50.
ZoneState0840::Entry* ZoneState0840::FindEntryByState(int state)
{
    if (!IsEntryStateValid(state)) return 0;
    for (int i = 0; i < 30; ++i)
    {
        Entry* entry = &entries[i];
        if (entry->flags.state == state) return entry;
    }
    return 0;
}

// Original: arm9/main @ 0x0209859C; symbol: _ZN13ZoneState084021FindEntryByIdentifierEPKv; size: 0x50.
ZoneState0840::Entry* ZoneState0840::FindEntryByIdentifier(const void* identifier)
{
    Entry* entry;
    for (int i = 0; i < 30; ++i)
    {
        entry = &entries[i];
        if (!RuntimeMemory_CompareByteRanges(identifier, entry->identifier, 6)) return entry;
    }
    return 0;
}

// Original: arm9/main @ 0x020985EC; symbol: _ZN13ZoneState084016FindEntryByValueEi; size: 0x44.
ZoneState0840::Entry* ZoneState0840::FindEntryByValue(int value)
{
    if (value < 0) return 0;
    for (int i = 0; i < 30; ++i)
    {
        Entry* entry = &entries[i];
        if (entry->value.value == value) return entry;
    }
    return 0;
}
