#include <globaldefs.h>
ARM
extern "C" int Combat_ClearCurrentResultNodeSlot(...);
extern "C" int CombatStatus_ClearAilmentModeOne(...);
extern "C" int Combat_AppendResultMessage(...);
extern "C" int Combat_SelectMessageForPartyOrMonster(...);
extern "C" int Combat_SetResultMaskFlag(...);
extern "C" int CombatStatus_HasAilmentModeTwo(...);
extern "C" int CombatStatus_HasAilmentModeOne(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_PopulateResultWithCurrentHealthAndMagic(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021DBC64; symbol: CreateCombatRecordAndClearConditionalStatusFlags.
extern "C" char* Combat_ClearAilmentModesAndBuildActionResult(char*self,int unused,int index,char*descriptor,int unused4,int unused5,unsigned char apply){
char*combatant=C(_Z16GetCombatantByIDii(P(self,16),index));if(!combatant)return 0;unsigned mask[2];mask[0]=0;mask[1]=0;unsigned value;if((CombatStatus_HasAilmentModeOne(P(combatant,312))||CombatStatus_HasAilmentModeTwo(P(combatant,312)))&&apply){value=84;CombatStatus_ClearAilmentModeOne(P(combatant,312));Combat_SetResultMaskFlag(P(self,16),mask,17);W(self,20)++;}else{struct Packed{char pad[36];unsigned low:10;unsigned a:10;unsigned b:10;unsigned high:2;};value=Combat_SelectMessageForPartyOrMonster(index,((Packed*)descriptor)->a,((Packed*)descriptor)->b);B(self,117)=0;}char*record=C(Combat_ClearCurrentResultNodeSlot(P(self,16)));if(!record)return 0;Combat_AppendResultMessage(P(self,16),record,value);struct Flag{unsigned char low:7;unsigned char enabled:1;};Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),record,combatant,0,*(unsigned long long*)mask,((Flag*)(P(self,12)+28))->enabled!=0);return record;
}
