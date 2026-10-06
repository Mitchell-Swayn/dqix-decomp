#include <globaldefs.h>

struct Function020425b4Table
{
    unsigned int unknown_000;
    unsigned int count;
    unsigned int unknown_008;
    unsigned int unknown_00c;
    unsigned int records;
};

// The BSS address is the start of a table of pointers, not one table object.
extern "C" Function020425b4Table* data_0210782c[];

extern "C" ARM unsigned int* func_020425b4(int index, unsigned int tableIndex)
{
    Function020425b4Table* table = data_0210782c[tableIndex];
    if (index >= 0 && static_cast<unsigned int>(index) < table->count)
    {
        unsigned int* records = reinterpret_cast<unsigned int*>(table->records);
        return records + index * 2;
    }
    else
        return 0;
}
