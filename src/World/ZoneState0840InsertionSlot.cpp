#include "World/Zone3DEmbeddedState.h"

int ZoneState0840::PrepareEntryInsertionSlot()
{
    if (!unknown_1b38) return 0;
    int destinationIndex = 0;
    int clearedIndex = 0;
    int freeIndex;
    bool allStored;
    int i = 0;
    freeIndex = -1;
    allStored = true;
    for (; i < 30; ++i)
    {
        Entry* entry = &entries[i];
        if (!entry->value.low)
        {
            freeIndex = i;
            break;
        }
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) allStored = false;
    }
    if (freeIndex == 0) return 0;
    if (freeIndex != -1)
    {
        if (allStored)
        {
            if (freeIndex < 6) return freeIndex;
            entries[freeIndex] = entries[unknown_1b74];
            entries[unknown_1b74].Reset();
            return unknown_1b74;
        }
        destinationIndex = freeIndex;
    }
    else
    {
        for (int i = 29; i >= 0; --i)
        {
            Entry* entry = &entries[i];
            int kind = entry->flags.kind;
            if (kind == 9 || kind == 10) continue;
            if (!ContainsStoredValue(entry->value.value))
            {
                destinationIndex = i;
                break;
            }
        }
    }
    for (int i = destinationIndex - 1; i >= 0; --i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value))
        {
            clearedIndex = i;
            entries[destinationIndex] = *entry;
            destinationIndex = i;
        }
    }
    entries[clearedIndex].Reset();
    for (int i = 0; i < 6; ++i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) entry->flags.kind = 2;
    }
    for (int i = 6; i < 12; ++i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) entry->flags.kind = 3;
    }
    for (int i = 12; i < 18; ++i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) entry->flags.kind = 4;
    }
    for (int i = 18; i < 24; ++i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) entry->flags.kind = 5;
    }
    for (int i = 24; i < 30; ++i)
    {
        Entry* entry = &entries[i];
        int kind = entry->flags.kind;
        if (kind == 9 || kind == 10) continue;
        if (!ContainsStoredValue(entry->value.value)) entry->flags.kind = 6;
    }
    if (clearedIndex < 6) return clearedIndex;
    entries[clearedIndex] = entries[unknown_1b74];
    entries[unknown_1b74].Reset();
    return unknown_1b74;
}
