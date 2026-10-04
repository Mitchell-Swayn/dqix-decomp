#include "World/WorldScriptArrayList.h"

extern "C" WorldScriptArrayEntry* func_0208d994(
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
