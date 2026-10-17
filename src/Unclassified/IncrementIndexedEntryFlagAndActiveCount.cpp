#include <globaldefs.h>

struct Entry28 { unsigned char prefix[0x24]; unsigned char flag; unsigned char tail[3]; };

// Original: arm9/main @ 0x0203C6B8; symbol: func_0203c6b8; size: 0x44.
extern "C" void IncrementIndexedEntryFlagAndActiveCount(unsigned char *state, int index) {
    if (index < 0) return;
    Entry28 *entry = (Entry28 *)(state + 4) + (short)index;
    if (entry->flag == 0) {
        entry->flag = 1;
        unsigned short *count = (unsigned short *)(state + 0x512);
        *count = *count + 1;
        return;
    }
    entry->flag = entry->flag + 1;
}
