// Original locations for overloaded or compiler-generated definitions in this unit:
// Original: arm9/main @ 0x02098834; symbol: _ZN13ZoneState08405EntryaSERKS0_; size: 0xD8. (ZoneState0840::Entry::operator=(ZoneState0840::Entry const&))
#include "World/Zone3DEmbeddedState.h"

extern "C" {
    int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);
    int RTC_GetDate(void*);
}

// Original: arm9/main @ 0x02098630; symbol: _ZN13ZoneState08408AddEntryEPKNS_5EntryEbb; size: 0x204.
bool ZoneState0840::AddEntry(const Entry* entry, bool incrementValue, bool updateTier)
{
    int i;
    if (!entry->parameters6c.unknown26) return false;
    for (i = 0; i < 30; ++i)
        if (!RuntimeMemory_CompareByteRanges(entries[i].identifier, entry->identifier, 6)) return false;
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
    if (!RTC_GetDate(date))
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

