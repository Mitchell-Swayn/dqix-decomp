#include "System/RuntimeUnwindTable.h"
#pragma optimize_for_size off
extern "C" const unsigned char* func_0200f2bc(const unsigned char* cursor)
{
    unsigned char flags = cursor[0];
    unsigned int ignored;
    cursor += 2;
    cursor = func_0200d9e4(cursor, &ignored);
    if (flags & 0x40)
        cursor = func_0200d9e4(cursor, &ignored);
    return cursor;
}
