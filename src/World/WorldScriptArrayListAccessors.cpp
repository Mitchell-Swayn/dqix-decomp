#include "World/WorldScriptArrayList.h"

extern "C" char* func_0208d9e8(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    return entry ? entry->unknown4 : 0;
}

extern "C" char* func_0208da00(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    return entry ? entry->unknown8 : 0;
}

extern "C" char* func_0208da18(WorldScriptArrayList* list, int key, int selector)
{
    char* value = 0;
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    if (entry)
    {
        switch (selector)
        {
        case 1: value = entry->values->values[0]; break;
        case 2: value = entry->values->values[1]; break;
        case 3: value = entry->values->values[2]; break;
        case 4: value = entry->values->values[3]; break;
        case 5: value = entry->values->values[4]; break;
        case 6: value = entry->values->values[5]; break;
        case 7: value = entry->values->values[6]; break;
        case 8: value = entry->values->values[7]; break;
        }
    }
    return value;
}

extern "C" char* func_0208dac4(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    return entry ? entry->unknown10 : 0;
}

extern "C" char* func_0208dadc(WorldScriptArrayList* list, int key)
{
    WorldScriptArrayEntry* entry = func_0208d994(list, key);
    return entry ? entry->unknown14 : 0;
}
