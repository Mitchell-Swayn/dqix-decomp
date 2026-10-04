#include "World/WorldScriptArrayList.h"

extern "C" WorldScriptArrayEntry* func_0208d994(
    WorldScriptArrayList* list, int key);

extern "C" unsigned int func_0208d9e8(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    return entry != 0 ? entry->unknown4 : 0;
}
