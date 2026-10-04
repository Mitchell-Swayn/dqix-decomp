#include "World/Zone3DEmbeddedState.h"

extern "C" int func_02001aec(const void*, const void*, unsigned int);

bool ZoneState0840::IsEntryIdentifierAvailable(const Entry* entry)
{
    if (!entry->parameters6c.unknown26) return false;
    for (int i = 0; i < 30; ++i)
    {
        if (!func_02001aec(entries[i].identifier, entry->identifier, 6)) return false;
    }
    return true;
}

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
