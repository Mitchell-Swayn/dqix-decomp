#include <globaldefs.h>
ARM
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView *descriptor; };
struct Record { unsigned char padding[0x22]; unsigned short mode:2; unsigned short rest:14; };
struct A { char pad[0x14]; unsigned int flags; char pad2[10]; unsigned short mode:2; };
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_HasSleep(unsigned int* p);
extern "C" int CombatEffect_TargetHasConfusion(unsigned char*);
extern "C" ARM int CombatEffect_TargetHasParalysis(LinkedDescriptorView* self);
extern "C" ARM int Combat_HasActionRestriction(LinkedDescriptorView* self);
extern "C" int CombatStatus_HasAilmentModeOne(Record* p);
extern "C" int CombatStatus_HasAilmentModeTwo(A *p);
extern "C" ARM int CombatEffect_TargetHasDazzle(void*);
extern "C" int CombatEffect_TargetHasFizzle(unsigned char*);
struct StatusFields{signed a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,rest:2;};
extern "C" bool CombatEffect_TargetHasEerieLight(const void*);
extern "C" void _Z19ApplyCombatantBuffsii(int,int);
extern "C" void CombatStatus_ClearSleep(char *p);
extern "C" void CombatStatus_ClearConfusion(char* p);
extern "C" void CombatStatus_ClearParalysis(unsigned char* p);
extern "C" void CombatStatus_ClearActionRestriction(unsigned char* p);
extern "C" void CombatStatus_ClearAilmentModeOne(char* p);
extern "C" void CombatStatus_ClearAilmentModeTwo(char *p);
extern "C" void CombatStatus_ClearDazzle(char *p);
extern "C" void CombatStatus_ClearFizzle(char *p);
extern "C" void CombatantState_ClearEerieLight(char* p);
extern "C" void CombatStatus_ClearAttackStage(char *p);
extern "C" void CombatStatus_ClearDefenseStage(char* p);
extern "C" void CombatStatus_ClearAgilityStage(unsigned char* p);
extern "C" void CombatStatus_ClearCharmStage(char *p);
extern "C" void CombatStatus_ClearMagicalMightStage(char* p);
extern "C" void CombatStatus_ClearMagicalMendingModifier(unsigned char* p);
extern "C" void CombatStatus_ClearSpellResistanceStage(char *p);
extern "C" void CombatStatus_ClearBreathResistanceStage(char* p);
extern "C" void CombatStatus_ClearEvasionStage(unsigned char* p);
extern "C" void CombatStatus_ClearShieldBlockStage(char *p);
struct ByteFlag{unsigned char set:1,high:7;};
// Original: arm9/ov024 @ 0x021EAE14; symbol: func_ov024_021eae14; size: 0x278.
// Clears flagged and negative packed statuses, counts mutations and reapplies combatant buffs.
extern "C" int Combat_ClearNegativeStatusesAndReapplyBuffs(char* self,int index){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!object)return 0;int count=0;int changed=0;
 if(CombatStatus_HasSleep(*(unsigned**)(object+0x138))){CombatStatus_ClearSleep(*(char**)(object+0x138));++count;changed=1;}
 if(CombatEffect_TargetHasConfusion((unsigned char*)object)){CombatStatus_ClearConfusion(*(char**)(object+0x138));++count;changed=1;}
 if(CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)){CombatStatus_ClearParalysis(*(unsigned char**)(object+0x138));++count;changed=1;}
 if(Combat_HasActionRestriction((LinkedDescriptorView*)object)){CombatStatus_ClearActionRestriction(*(unsigned char**)(object+0x138));++count;changed=1;}
 if(CombatStatus_HasAilmentModeOne(*(Record**)(object+0x138))){CombatStatus_ClearAilmentModeOne(*(char**)(object+0x138));++count;}
 if(CombatStatus_HasAilmentModeTwo(*(A**)(object+0x138))){CombatStatus_ClearAilmentModeTwo(*(char**)(object+0x138));++count;}
 if(CombatEffect_TargetHasDazzle(object)){CombatStatus_ClearDazzle(*(char**)(object+0x138));++count;}
 if(CombatEffect_TargetHasFizzle((unsigned char*)object)){CombatStatus_ClearFizzle(*(char**)(object+0x138));++count;}
 if(CombatEffect_TargetHasEerieLight((unsigned char*)object)){CombatantState_ClearEerieLight(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->a<0){CombatStatus_ClearAttackStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->b<0){CombatStatus_ClearDefenseStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->c<0){CombatStatus_ClearAgilityStage(*(unsigned char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->d<0){CombatStatus_ClearCharmStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->e<0){CombatStatus_ClearMagicalMightStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->f<0){CombatStatus_ClearMagicalMendingModifier(*(unsigned char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->g<0){CombatStatus_ClearSpellResistanceStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->h<0){CombatStatus_ClearBreathResistanceStage(*(char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->j<0){CombatStatus_ClearEvasionStage(*(unsigned char**)(object+0x138));++count;}
 if(((StatusFields*)(*(char**)(object+0x138)+0x58))->i<0){CombatStatus_ClearShieldBlockStage(*(char**)(object+0x138));++count;}
 if(changed)((ByteFlag*)(*(char**)(object+0x138)+0x3b))->set=1;
 _Z19ApplyCombatantBuffsii(*(int*)(self+16),index);return count;
}
