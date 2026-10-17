#include <globaldefs.h>
ARM
struct GameState; struct Entry; struct Table; struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_ClearObjectByIndex(GameState*,unsigned);
extern "C" void *Object_GetGlobalThirtyTwoEntryContainer();
extern "C" Entry* FindActiveEntryByHalfwordId(Table* t,unsigned id);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int i);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x02160D14; symbol: func_ov001_02160d14; size: 0x94.
extern "C" int Resource_ScriptClearIndexedObject(char *params) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    Table *table = (Table*)Object_GetGlobalThirtyTwoEntryContainer();
    int id = ReadScriptParameterAsInteger((IntegerParameterView*)params);
    int index = ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger((IntegerParameterView*)(params + 8)));
    if (index < 160 || index > 191) return 0;
    char *entry = (char*)FindActiveEntryByHalfwordId(table, id);
    if (!entry) return 0;
    unsigned char *object = *(unsigned char**)(entry + 24);
    if (!object) return 0;
    object[0xd4] &= ~1;
    GameState_ClearObjectByIndex(state, index);
    return 1;
}
