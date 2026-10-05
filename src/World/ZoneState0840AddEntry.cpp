#include "World/Zone3DEmbeddedState.h"

extern "C" {
    int func_02001aec(const void*, const void*, unsigned int);
    int func_020cf0fc(void*);
}

bool ZoneState0840::AddEntry(const Entry* entry, bool incrementValue, bool updateTier)
{
    int i;
    if (!entry->parameters6c.unknown26) return false;
    for (i = 0; i < 30; ++i)
        if (!func_02001aec(entries[i].identifier, entry->identifier, 6)) return false;
    int index = PrepareEntryInsertionSlot();
    if (incrementValue) ++unknown_1b34;
    unknown_1b38 = 0;
    Entry* current = entries;
    for (int j = 0; j < 30; ++j, ++current)
        if (current->value.value) ++unknown_1b38;
    ++unknown_1b38;
    if (unknown_1b38 > 30) unknown_1b38 = 30;
    Entry* destination = &entries[index];
    *destination = *entry;
    destination->flags.kind = 2;
    destination->value.low = 2;
    destination->flags.unknown30 = 1;
    destination->value.value = unknown_1b34;
    int date[4];
    if (!func_020cf0fc(date))
    {
        entries[index].byteFlags.low = (unsigned char)date[0];
        entries[index].flags.unknown15 = date[1];
        entries[index].flags.unknown19 = date[2];
    }
    if (updateTier) UpdateEntryCountTier();
    int value = destination->value.value;
    for (i = 0; i < 3; ++i)
    {
        if (unknown_1b68[i] == -1)
        {
            unknown_1b68[i] = value;
            ++unknown_1b74;
            break;
        }
    }
    return true;
}

