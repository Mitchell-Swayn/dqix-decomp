#include "CountCache.h"

// A missing pair leaves both outputs unchanged, as in the original.
extern "C" void func_ov004_021546c0(CountCache* cache, int primaryKey, int secondaryKey,
                                  unsigned char* availableCount, unsigned char* totalCount)
{
    for (unsigned char i = 0; i < 20; ++i) {
        CountRecord* record = &cache->records[i];
        int first = record->primaryKey;
        if (first == primaryKey && record->secondaryKey == secondaryKey) {
            *availableCount = record->availableCount;
            *totalCount = record->totalCount;
            return;
        }
    }
}
