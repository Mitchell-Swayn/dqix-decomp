#include "System/Cache.h"
#include "System/Memory.h"

extern "C" {

// Return the number of bytes processed, including for the zero-fill operation.
unsigned int func_020d84f8(void* destination, unsigned int length)
{
    VectorizedMemset(destination, 0, length);
    CleanInvalidateCacheRange(destination, length);
    return length;
}

unsigned int func_020d8524(void* destination, const void* source, unsigned int length)
{
    VectorizedInvertedMemcpy(source, destination, length);
    CleanInvalidateCacheRange(destination, length);
    return length;
}
}
