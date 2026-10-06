#include "Memory/SignedAllocator.h"

extern "C" void func_020bc658(SignedAllocatorList* list,
    SignedAllocatorHeader* allocator)
{
    SignedAllocatorHeader* current = list->ElementAfter(NULL);
    if (current != NULL)
    {
        do
        {
            if (*((unsigned char*)allocator + 0x3D) <
                *((unsigned char*)current + 0x3D))
                break;
            current = list->ElementAfter(current);
        } while (current != NULL);
    }

    list->InsertBefore(current, allocator);
    allocator->pPrevAllocator = (SignedAllocatorHeader*)list;
}
