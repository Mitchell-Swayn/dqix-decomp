#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" char* GameObject_GetLinkedActionDataWhenEnabled(char*);extern "C" int CharacterState_GetLearnedSkillMask(unsigned char*,int);struct Record;extern "C" Record* BattleMenu_FindActionDefinition(unsigned char*,unsigned);extern "C" void* BattleMenu_FindItemByEquipmentKey(char*,int);struct ObjectFlags{unsigned one:1;unsigned two:1;unsigned rest:30;};struct Category{unsigned low:8;unsigned kind:2;unsigned high:22;};
// Original: arm9/ov000 @ 0x02171ffc; symbol: Combat_ResolveEquippedActionSelectionMode.
extern "C" unsigned BattleMenu_ResolveEquippedActionTargetMode(char* self){
char* object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),I(self,0x4c));if(!object)return 2;int id=S(self,0x26);unsigned mode=2;if(C(self,0x1c)==4){char* equipment=(char*)BattleMenu_FindItemByEquipmentKey(self,S(self,0x2c));if(!equipment)return mode;id=S(equipment,0x16);}if(id==522)return 3;char* record=(char*)BattleMenu_FindActionDefinition((unsigned char*)self,(unsigned short)id);if(!record)return 2;if(id==1){if(object){char* linked=GameObject_GetLinkedActionDataWhenEnabled(object);if(linked&&S(linked,24)>0){ObjectFlags* flags=(ObjectFlags*)(V(object,0x150)+0x2f4);if(flags->two)mode=3;else if(flags->one)mode=4;}}}else{unsigned kind=((Category*)(record+8))->kind;if(kind==1)mode=U(record,20)>>28;else if(kind==2)mode=U(record,20)>>28;}if(mode==6&&object){mode=2;if(CharacterState_GetLearnedSkillMask((unsigned char*)V(object,0x150),230))mode=3;}return mode;
}
