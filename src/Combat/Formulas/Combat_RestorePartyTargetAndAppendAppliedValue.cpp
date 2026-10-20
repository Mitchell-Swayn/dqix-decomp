#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" bool GameObject_IsDead(void*);
extern "C" int CharacterState_TestActiveMappedModifierBit20(unsigned char*);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int GameState_AddCombatantValueUpToMaximum(void*,int,unsigned short,unsigned short*);
extern "C" void Combat_AppendCombatantDescriptorRecords(unsigned char*,int,int,short);
struct Flags8 {unsigned amount:8;unsigned category:2;unsigned rest:22;};
struct Flags18 {unsigned low:5;unsigned kind:7;unsigned mode:4;unsigned high:16;};
static inline int IsParty(int id){return id>=0&&id<=3;}
// Original: arm9/ov024 @ 0x021E556C; symbol: func_ov024_021e556c; size: 0x154.
// Restores the target's descriptor amount and appends its applied value when action, target and active-entry gates permit.
extern "C" void Combat_RestorePartyTargetAndAppendAppliedValue(char* self,int source,int target,char* descriptor,int amount){
 void* state=_ZN9GameState11GetInstanceEv();
 if(!_Z16GetCombatantByIDii(*(int*)(self+16),target))return;
 if(!(*(unsigned*)(descriptor+16)&1))return;
 if(((Flags8*)(descriptor+8))->category!=1)return;
 if(!IsParty(target))return;if(IsParty(source))return;
 if(!((Flags8*)(descriptor+8))->amount)return;
 if(((Flags18*)(descriptor+24))->kind==1&&amount<=0)return;
 if(((Flags18*)(descriptor+24))->mode!=2)return;
 if(!*(unsigned char*)(self+0x75))return;
 char* object=(char*)GameState_GetObjectWithFlag100(state,target);if(!object)return;
 if(GameObject_IsDead(object))return;
 if(!CharacterState_TestActiveMappedModifierBit20(*(unsigned char**)(object+0x150)))return;
 short applied=0;
 int code=((int(*)(void*,int,int,unsigned short*))GameState_AddCombatantValueUpToMaximum)(*(void**)(self+16),target,((Flags8*)(descriptor+8))->amount,(unsigned short*)&applied);
 ((void(*)(unsigned char*,int,int,int))Combat_AppendCombatantDescriptorRecords)(*(unsigned char**)(self+16),target,applied,code);
}
