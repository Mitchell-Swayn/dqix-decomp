#include <globaldefs.h>

struct Function0204254cEntry
{
    const void* value;
    unsigned char unknown_004;
    signed char selector;
    unsigned char unknown_006[2];
};

struct Function0204254cList
{
    unsigned int unknown_000;
    unsigned int count;
    unsigned int unknown_008;
    unsigned int unknown_00c;
    Function0204254cEntry* entries;
};

extern "C" Function0204254cList* data_0210782c[];
extern "C" int func_02001aec(const void*, const void*, unsigned int);

extern "C" ARM Function0204254cEntry* func_0204254c(const void* value, unsigned int listIndex)
{
    if (!value)
        return 0;

    Function0204254cList* list = data_0210782c[listIndex];
    for (unsigned int i = 0; i < list->count; ++i)
    {
        Function0204254cEntry* entry = &list->entries[i];
        int length = entry->selector;
        length = (length << 26) >> 26;
        if (func_02001aec(entry->value, value, static_cast<unsigned int>(length)) == 0)
            return entry;
    }
    return 0;
}
