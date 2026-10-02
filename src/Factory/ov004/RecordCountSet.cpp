#include "CountCache.h"

extern "C" void func_ov004_021545f0(CountCache* cache, unsigned char index,
                                  short primaryKey, short secondaryKey,
                                  unsigned char availableCount, unsigned char totalCount)
{
    CountRecord* record = &cache->records[index];
    record->primaryKey = primaryKey;
    record->secondaryKey = secondaryKey;
    record->availableCount = availableCount;
    record->totalCount = totalCount;
}
