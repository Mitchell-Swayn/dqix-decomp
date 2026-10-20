#include "std_library_functions.h"

struct IndexedRecordTable
{
    uint16_t unknown0;
    uint8_t count;
    uint8_t unknown3;
    const uint8_t* records;
};

// Original: arm9/main @ 0x020283FC; symbol: func_020283fc; size: 0x34.
extern "C" int IndexedRecordTable_FindRecordIndexByValue(const IndexedRecordTable* table, int value)
{
    for (int i = 0; i < table->count; ++i)
    {
        if (table->records[i * 16] == value)
            return i;
    }
    return -1;
}
