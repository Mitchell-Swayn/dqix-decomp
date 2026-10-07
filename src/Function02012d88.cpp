#include "Memory/AllocatorUnion.h"

// USA: func_02012d88
extern "C" void* func_02012d88(AllocatorUnion* allocator, unsigned int size)
{
    size = (size + 3) & ~3u;
    volatile void* result = allocator->Allocate(size);
    if (result == 0)
        return 0;
    return (void*)result;
}
