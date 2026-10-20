#include "World/WorldScriptArrayList.h"

// Original: arm9/main @ 0x0208D928; symbol: func_0208d928; size: 0x6C.
extern "C" void WorldScriptArrayList_AppendEntryWithinCapacity(WorldScriptArrayList* list,
                               const WorldScriptArrayEntry* entry)
{
    if (list->entries == 0) return;
    short index = list->count;
    if (list->capacity <= index) return;
    WorldScriptArrayEntry* destination = &list->entries[index];
    destination->key = entry->key;
    destination->unknown4 = entry->unknown4;
    destination->unknown8 = entry->unknown8;
    destination->unknownC = entry->unknownC;
    destination->unknown10 = entry->unknown10;
    destination->unknown14 = entry->unknown14;
    list->count = (short)(list->count + 1);
}
