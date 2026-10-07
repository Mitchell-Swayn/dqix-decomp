#include "Memory/SignedAllocator.h"
#include "Memory/HMRFAllocator.h"

extern "C" void func_020bdbe0(SignedAllocatorList* list);

extern "C" int func_020bdc24(SignedAllocatorList* list)
{
    HMRFAllocator* allocator = (HMRFAllocator*)list->pFirst;
    void* storage = allocator->Allocate(0x14, 4);
    if (storage == NULL)
        return 0;

    func_020bdbe0((SignedAllocatorList*)storage);
    SignedAllocatorList* children = (SignedAllocatorList*)((char*)list + 4);
    children->InsertAtEnd((SignedAllocatorHeader*)storage);
    return 1;
}
