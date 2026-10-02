#include "CountCache.h"

extern "C" {
CountCache* data_ov004_021707c0;

// The original secondary search is embedded in the summation routine.
// MWCC's project-wide -inline noauto otherwise emits it out of line.
#pragma always_inline on
static inline CountRecord* FindSecondary(CountCache* cache, int key)
{
    for (unsigned char i = 0; i < 20; ++i) {
        int recordKey = cache->records[i].secondaryKey;
        if (recordKey == key)
            return &cache->records[i];
    }
    return 0;
}

short func_ov004_021537e0()
{
    short total = 0;
    for (short key = 0; key <= 11; ++key) {
        CountRecord* record = FindSecondary(data_ov004_021707c0, key);
        if (record)
            total += record->totalCount;
    }
    return total;
}

CountRecord* func_ov004_021538b4(CountCache*, int);

short func_ov004_02153860()
{
    short total = 0;
    for (short key = 1; key <= 6; ++key) {
        CountRecord* record = func_ov004_021538b4(data_ov004_021707c0, key);
        if (record)
            total += record->totalCount;
    }
    return total;
}

#pragma dont_inline on
CountRecord* func_ov004_021538b4(CountCache* cache, int key)
{
    for (unsigned char i = 0; i < 20; ++i) {
        int recordKey = cache->records[i].primaryKey;
        if (recordKey == key)
            return &cache->records[i];
    }
    return 0;
}

short func_ov004_021538f0()
{
    short total = 0;
    for (short key = 7; key <= 7; ++key) {
        CountRecord* record = func_ov004_021538b4(data_ov004_021707c0, key);
        if (record)
            total += record->totalCount;
    }
    return total;
}

}
