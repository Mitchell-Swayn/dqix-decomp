#include <globaldefs.h>
ARM
#pragma always_inline on

struct Header {
    unsigned count : 12;
    unsigned rest : 19;
    unsigned owned : 1;
    unsigned char *first, *second;
};

extern "C" int ScriptRecordTable_ReadSignedSearchKey(int);

static inline void *FindRecordByExtractedKey(Header *table, int key, int (*reader)(int))
{
    unsigned char *records = table->first;
    if (!records || (unsigned)reader == 0)
        return 0;
    int count = table->count;
    if (!count)
        return 0;
    int low = 0, high = count - 1;
    while (low <= high) {
        int middle = low + ((high - low + 1) >> 1);
        unsigned char *entry = records + middle * 44;
        int found = reader((int)entry);
        if (found == key)
            return entry;
        if (found > key)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return 0;
}

// Original: arm9/main @ 0x0209A004; symbol: func_0209a004; size: 0x84.
// Searches sorted 44-byte records by their signed halfword at offset 0x28.
extern "C" void *ScriptRecordTable_FindEntryBySignedKey(Header *table, int key)
{
    return FindRecordByExtractedKey(table, key, ScriptRecordTable_ReadSignedSearchKey);
}
