#include "Memory/AllocatorUnion.h"

extern "C" void func_02012da4(AllocatorUnion* allocator, void* data)
{
    allocator->Free(data);
}
