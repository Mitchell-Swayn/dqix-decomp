#pragma once

// Layout established by the 126-byte allocation and its initialization at
// 0x02154350. Names describe observed fields; gameplay categories are unresolved.
struct CountRecord {
    short primaryKey;
    short secondaryKey;
    unsigned char availableCount;
    unsigned char totalCount;
};

struct CountCache {
    CountRecord records[20];
    short availableCount;
    short totalCount;
    unsigned char state;
};

typedef char CountRecordSizeCheck[sizeof(CountRecord) == 6 ? 1 : -1];
typedef char CountCacheSizeCheck[sizeof(CountCache) == 126 ? 1 : -1];

extern "C" CountCache* data_ov004_021707c0;
