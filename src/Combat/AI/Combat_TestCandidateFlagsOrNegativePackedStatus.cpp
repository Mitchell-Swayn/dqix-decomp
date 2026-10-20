#include <globaldefs.h>
ARM
struct LinkedDescriptorView;struct A;struct Record;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_HasSleep(unsigned*);
extern "C" int CombatEffect_TargetHasConfusion(unsigned char*);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" int Combat_HasActionRestriction(LinkedDescriptorView*);
extern "C" int CombatStatus_HasAilmentModeOne(Record*);
extern "C" int CombatStatus_HasAilmentModeTwo(A*);
extern "C" int CombatEffect_TargetHasDazzle(void*);
extern "C" int CombatEffect_TargetHasFizzle(unsigned char*);
struct StatusFields{signed a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,rest:2;};
// Original: arm9/ov024 @ 0x021EDCC8; symbol: func_ov024_021edcc8; size: 0x164.
// Tests eight blocking flags and ten signed packed status fields, preserving the original j-before-i order.
extern "C" int Combat_TestCandidateFlagsOrNegativePackedStatus(int* self,int index){
 char* object=_Z16GetCombatantByIDii(*self,index);if(!object)return 0;
 if(CombatStatus_HasSleep(*(unsigned**)(object+0x138)))return 1;
 if(CombatEffect_TargetHasConfusion((unsigned char*)object))return 1;
 if(CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object))return 1;
 if(Combat_HasActionRestriction((LinkedDescriptorView*)object))return 1;
 if(CombatStatus_HasAilmentModeOne(*(Record**)(object+0x138)))return 1;
 if(CombatStatus_HasAilmentModeTwo(*(A**)(object+0x138)))return 1;
 if(CombatEffect_TargetHasDazzle(object))return 1;
 if(CombatEffect_TargetHasFizzle((unsigned char*)object))return 1;
 StatusFields* status=(StatusFields*)(*(char**)(object+0x138)+0x58);
 if(status->a<0)return 1;if(status->b<0)return 1;if(status->c<0)return 1;if(status->d<0)return 1;if(status->e<0)return 1;
 if(status->f<0)return 1;if(status->g<0)return 1;if(status->h<0)return 1;if(status->j<0)return 1;return status->i<0;
}
