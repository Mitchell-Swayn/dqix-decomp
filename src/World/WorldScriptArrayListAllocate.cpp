#include "World/WorldScriptArrayList.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_0208d8ec(WorldScriptArrayList* list,
                               SafeAllocator* allocator, int capacity)
{
    if (allocator == 0) return;
    if (capacity <= 0) return;
    list->count = 0;
    list->capacity = (short)capacity;
    list->entries = (WorldScriptArrayEntry*)
        allocator->Allocate(capacity * (int)sizeof(WorldScriptArrayEntry));
}
\n