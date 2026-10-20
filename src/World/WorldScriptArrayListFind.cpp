#include "World/WorldScriptArrayList.h"

// Original: arm9/main @ 0x0208D994; symbol: func_0208d994; size: 0x54.
extern "C" WorldScriptArrayEntry* WorldScriptArray_FindEntryByKey(
    WorldScriptArrayList* list, int key)
{
    if (key < 0) return 0;
    int index = 0;
    while (index < list->count)
    {
        int offset = index * 24;
        WorldScriptArrayEntry* entries = list->entries;
        short entryKey = *(short*)((char*)entries + offset);
        if (key == entryKey) return (WorldScriptArrayEntry*)((char*)entries + offset);
        index = (short)(index + 1);
    }
    return 0;
}
