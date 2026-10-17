#include "World/WorldScriptArrayList.h"

extern "C" WorldScriptArrayEntry* WorldScriptArray_FindEntryByKey(
    WorldScriptArrayList* list, int key);

// Original: arm9/main @ 0x0208D9E8; symbol: func_0208d9e8; size: 0x18.
extern "C" unsigned int ReadResolvedWorldScriptEntryField4OrZero(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = WorldScriptArray_FindEntryByKey(list, key);
    return entry != 0 ? entry->unknown4 : 0;
}
