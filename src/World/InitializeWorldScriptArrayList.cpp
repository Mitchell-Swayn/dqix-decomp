#include "World/WorldScriptArrayList.h"

// Original: arm9/main @ 0x0208D82C; symbol: func_0208d82c; size: 0x28.
extern "C" void InitializeWorldScriptArrayList(WorldScriptArrayList* list)
{
    list->entries = 0;
    list->capacity = 0;
    list->count = 0;
    list->unknown8 = 0;
    list->unknownC = 0;
    list->unknownE = 0xfff;
}
