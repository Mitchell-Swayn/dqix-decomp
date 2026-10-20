#include <globaldefs.h>
ARM
struct GameState; struct Entry; struct Table; struct IntegerParameterView;
struct Object3D;
struct ActiveObject { unsigned char pad[0xd4]; unsigned char active : 1; unsigned char rest : 7; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetIndexedObjectAndSlot(GameState*,int,Object3D*);
extern "C" void *ActorPool_GetGlobalInstance();
extern "C" Entry* ActorPool_FindActiveActorById(Table* t,unsigned id);
extern "C" int Script_ResolveEventObjectIndex(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x02160C78; symbol: func_ov001_02160c78; size: 0x9C.
extern "C" int Resource_ScriptSetIndexedObject(char *params) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    Table *table = (Table*)ActorPool_GetGlobalInstance();
    int id = Script_ReadParameterAsInteger((IntegerParameterView*)params);
    int index = Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger((IntegerParameterView*)(params + 8)));
    if (index < 160 || index > 191) return 0;
    char *entry = (char*)ActorPool_FindActiveActorById(table, id);
    if (!entry) return 0;
    ActiveObject *object = *(ActiveObject**)(entry + 24);
    if (!object) return 0;
    object->active = 1;
    GameState_SetIndexedObjectAndSlot(state, index, *(Object3D**)(entry + 24));
    return 1;
}
