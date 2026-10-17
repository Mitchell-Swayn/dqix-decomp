#include "System/Cache.h"
#include "System/Memory.h"

extern "C" {

// Return the number of bytes processed, including for the zero-fill operation.
// Original: arm9/main @ 0x020D84F8; symbol: func_020d84f8; size: 0x2C.
unsigned int Memory_ClearAndCleanInvalidateRangeReturningLength(void* destination, unsigned int length)
{
    VectorizedMemset(destination, 0, length);
    CleanInvalidateCacheRange(destination, length);
    return length;
}

// Original: arm9/main @ 0x020D8524; symbol: func_020d8524; size: 0x2C.
unsigned int CopyRangeCleanCacheAndReturnLength(void* destination, const void* source, unsigned int length)
{
    MI_CpuCopy8(source, destination, length);
    CleanInvalidateCacheRange(destination, length);
    return length;
}
}
