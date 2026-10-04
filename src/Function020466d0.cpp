#include "Memory/SafeAllocator.h"

extern "C" SafeAllocator* func_020466d0(SafeAllocator* allocator)
{
    allocator->ResetAllocatorPointer();
    return allocator;
}
