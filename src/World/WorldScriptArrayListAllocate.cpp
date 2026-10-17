#include "World/WorldScriptArrayList.h"
#include "Memory/SafeAllocator.h"

// Original: arm9/main @ 0x0208D8EC; symbol: func_0208d8ec; size: 0x3C.
extern "C" void AllocateWorldScriptArrayEntries(WorldScriptArrayList* list,
                               SafeAllocator* allocator, int capacity)
{
    if (allocator == 0) return;
    if (capacity <= 0) return;
    list->count = 0;
    list->capacity = (short)capacity;
    list->entries = (WorldScriptArrayEntry*)
        allocator->Allocate(capacity * (int)sizeof(WorldScriptArrayEntry));
}
