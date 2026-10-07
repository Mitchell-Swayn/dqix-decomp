#include "Memory/SignedAllocator.h"

extern "C" SignedAllocatorList data_0210f3d8;

extern "C" void func_020bc6a8(SignedAllocatorHeader* allocator)
{
    SignedAllocatorHeader* current = data_0210f3d8.ElementAfter(NULL);
    if (current != NULL)
    {
        do
        {
            if (*((unsigned char*)allocator + 0x3D) <
                *((unsigned char*)current + 0x3D))
                break;
            current = data_0210f3d8.ElementAfter(current);
        } while (current != NULL);
    }

    data_0210f3d8.InsertBefore(current, allocator);
}
