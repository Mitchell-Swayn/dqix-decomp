#include "World/Zone3DEmbeddedState.h"

extern "C" int func_02001aec(const void*, const void*, unsigned int);

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

ZoneState0840::Entry* ZoneState0840::FindEntryByIdentifier(const void* identifier)
{
    Entry* entry;
    for (int i = 0; i < 30; ++i)
    {
        entry = &entries[i];
        if (!func_02001aec(identifier, entry->identifier, 6)) return entry;
    }
    return 0;
}

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
