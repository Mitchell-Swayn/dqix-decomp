#include "std_library_functions.h"

struct IndexedRecordTable
{
    uint16_t unknown0;
    uint8_t count;
    uint8_t unknown3;
    const uint8_t* records;
};

extern "C" int func_020283fc(const IndexedRecordTable* table, int value)
{
    for (int i = 0; i < table->count; ++i)
    {
        if (table->records[i * 16] == value)
            return i;
    }
    return -1;
}
