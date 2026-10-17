#include "Memory/SafeAllocator.h"

// Original: arm9/main @ 0x020466D0; symbol: func_020466d0; size: 0x14.
extern "C" SafeAllocator* SafeAllocator_ResetAndReturnPointer(SafeAllocator* allocator)
{
    allocator->ResetAllocatorPointer();
    return allocator;
}
