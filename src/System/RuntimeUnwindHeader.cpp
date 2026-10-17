#include "System/RuntimeUnwindTable.h"
#pragma optimize_for_size off
// Original: arm9/main @ 0x0200F2BC; symbol: func_0200f2bc; size: 0x30.
extern "C" const unsigned char* RuntimeUnwindHeader_SkipEncodedHeader(const unsigned char* cursor)
{
    unsigned char flags = cursor[0];
    unsigned int ignored;
    cursor += 2;
    cursor = RuntimeUnwind_ReadCompactUnsignedInteger(cursor, &ignored);
    if (flags & 0x40)
        cursor = RuntimeUnwind_ReadCompactUnsignedInteger(cursor, &ignored);
    return cursor;
}
