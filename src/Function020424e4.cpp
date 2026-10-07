// Search the selector's comparison records for a matching value.
struct Function020424e4Record
{
    const void* value;
    unsigned char unknown_04;
    signed char compareLength;
    unsigned char unknown_06[2];
};

struct Function020424e4List
{
    unsigned char unknown_00[4];
    unsigned int count;
    unsigned char unknown_08[8];
    Function020424e4Record* records;
};

extern "C" Function020424e4List* data_0210782c[];
extern "C" int func_02001aec(const void*, const void*, unsigned int);

extern "C" int func_020424e4(const void* value, unsigned int selector)
{
    if (value == 0)
        return -1;

    Function020424e4List* list = data_0210782c[selector];
    unsigned int i = 0;
    while (i < list->count)
    {
        Function020424e4Record* record = &list->records[i];
        int compareLength = record->compareLength;
        unsigned int length = static_cast<unsigned int>((compareLength << 26) >> 26);
        if (func_02001aec(record->value, value, length) == 0)
            return static_cast<int>(i);
        ++i;
    }
    return -1;
}
