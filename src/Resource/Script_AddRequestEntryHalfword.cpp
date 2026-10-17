#include <globaldefs.h>
ARM
struct List;
struct Entry { char pad[10]; unsigned short values[1]; };
struct IntegerParameterView;
extern "C" void* Object_GetGlobalRequestQueue();
extern "C" Entry* Object_FindBoundedIdEntryThrough204(List* p,int id);
extern "C" unsigned int ReadWordAtOffset0(void*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/main @ 0x0209D2A8; symbol: func_0209d2a8; size: 0x8C.
extern "C" int Script_AddRequestEntryHalfword(char *params) {
    List *queue = (List *)Object_GetGlobalRequestQueue();
    if (!queue) return 0;
    char *owner = (char *)ReadWordAtOffset0(queue);
    if (!owner) return 0;
    Entry *entry = Object_FindBoundedIdEntryThrough204(queue, ReadScriptParameterAsInteger((IntegerParameterView *)params));
    if (!entry) return 0;
    int index = ReadScriptParameterAsInteger((IntegerParameterView *)(params + 8));
    int current = entry->values[index];
    int amount = *(int *)(owner + 0x98);
    int result;
    if (current + amount >= 65535) result = 0;
    else {
        entry->values[index] += amount;
        result = 1;
    }
    return result;
}
