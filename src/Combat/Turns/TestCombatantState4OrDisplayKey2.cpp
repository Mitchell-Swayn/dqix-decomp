#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Object_GetGlobalSixteenEntryDisplayState();extern "C" int CombatScene_CollectCommandFinalTargets(void*,unsigned,int*);extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" int ObjectPool_CollectDisplayEntriesByTemplateKey(void*,int,void*,int);
// Original: arm9/ov000 @ 0x02162954; symbol: TestCombatantState4OrDisplayKey2; size: 0x98.
// Tests selected combatants for byteBE value4, then checks display records with key2.
extern "C" int TestCombatantState4OrDisplayKey2(char* self){void* gs=_ZN9GameState11GetInstanceEv();void* display=Object_GetGlobalSixteenEntryDisplayState();int indices[12];int count=CombatScene_CollectCommandFinalTargets(self,*(unsigned*)(self+0x55d8),indices);for(int i=0;i<count;i++){char* object=_ZN9GameState19GetCombatantByIndexEi(gs,indices[i]);if(object && *(unsigned char*)(object+0xbe)==4)return 1;}return ObjectPool_CollectDisplayEntriesByTemplateKey(display,2,0,0)>0;}
