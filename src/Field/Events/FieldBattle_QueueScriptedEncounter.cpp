#include <globaldefs.h>
ARM
class GameState; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *p,unsigned int n);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int FieldBattle_ResolveMonsterAndTreasureMapFlags(unsigned char* p,int i);
extern "C" void FieldBattle_InitializeCommand(void*);
extern "C" void FieldBattle_ConfigureEncounterRequest(void*,void*);
struct Descriptor { unsigned char type,index; unsigned short id,value,pad6; int key; unsigned char a,b,c,d; short field10; unsigned char mode,pad13; unsigned extra; };
// Original: arm9/ov017 @ 0x021B8BB0; symbol: func_ov017_021b8bb0; size: 0xC0.
extern "C" void FieldBattle_QueueScriptedEncounter(int key) {
    GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
    char *resources = (char *)GameResources_GetInstance();
    unsigned *list;
    void *record = *(void **)(resources + 0x3718);
    list = *(unsigned **)(resources + 0x36fc);
    FieldBattle_InitializeCommand(record);
    Descriptor descriptor;
    descriptor.type = 1;
    descriptor.index = 0;
    descriptor.id = 0;
    descriptor.value = 0;
    descriptor.key = -1;
    descriptor.a = 0;
    descriptor.b = 0;
    descriptor.c = 0;
    descriptor.field10 = -1;
    descriptor.mode = 2;
    descriptor.d = 0;
    descriptor.extra = 0;
    descriptor.index = GameState_ReadProtagonistObjectIndex(state);
    descriptor.id = 65535;
    descriptor.value = key + 0x8005;
    descriptor.key = key;
    FieldBattle_ResolveMonsterAndTreasureMapFlags((unsigned char *)&descriptor,descriptor.id);
    FieldBattle_ConfigureEncounterRequest(record,&descriptor);
    LinkedQueue_AppendAndMarkActive(list,(unsigned)record);
}
