#include "World/WorldScriptArrayList.h"

extern "C" void func_0208d928(WorldScriptArrayList* list,
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
\n