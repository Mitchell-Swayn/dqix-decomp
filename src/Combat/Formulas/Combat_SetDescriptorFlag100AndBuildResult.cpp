#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatStatus_CanApplyFizzle(char*);
extern "C" void CombatStatus_ApplyFizzle(char*);
extern "C" int CombatEffect_TargetHasFizzle(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
struct Mask{unsigned low,high;};struct Flags;
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};struct Flag{unsigned char low:7,set:1;};
// Original: arm9/ov024 @ 0x021DCED0; symbol: func_ov024_021dced0; size: 0x140.
// Sets descriptor flag100 and its six-count byte when allowed, selecting alternate feedback if already set.
extern "C" void* Combat_SetDescriptorFlag100AndBuildResult(char* self,int unused,int target,char* descriptor,int unused4,int unused5,unsigned char enabled){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 unsigned short code=0;
 if(CombatStatus_CanApplyFizzle(*(char**)(object+0x138))&&enabled){if(CombatEffect_TargetHasFizzle((unsigned char*)object))code=Combat_SelectMessageForPartyOrMonster(target,0x19,0x1a);else code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+32))->high,((PackedCodes*)(descriptor+36))->low);CombatStatus_ApplyFizzle(*(char**)(object+0x138));}
 else{code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);*(unsigned char*)(self+0x75)=0;}
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_SuppressMessageForExceptionalOutcome(self,*(Flags**)(self+12),&code);Combat_AppendResultMessage(*(void**)(self+16),record,code);
 ((void(*)(void*,void*,void*,int,unsigned long long,int))Combat_PopulateResultWithCurrentHealthAndMagic)(*(void**)(self+16),record,object,0,0ULL,((Flag*)(*(char**)(self+12)+0x1c))->set!=0);return record;
}
