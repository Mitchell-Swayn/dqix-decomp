#include <globaldefs.h>
ARM
struct Flags {unsigned pad:7;unsigned percent:7;unsigned rest:18;};
extern "C" {bool CombatStatus_CanApplyAilmentModeTwo(unsigned*);int CombatStatus_HasAilmentModeTwo(void*);void BattleAI_CacheActionPolicyEntry(void*,int);void SubmitPercentScaledDisplayRecord(void*,float,unsigned char);}
// Original: arm9/ov024 @ 0x021FD358; symbol: func_ov024_021fd358; size: 0x98.
extern "C" void UpdateConditionalDisplayPercentFromNestedState(char* p){
char* object=*(char**)(p+0x668);
if(!CombatStatus_CanApplyAilmentModeTwo(*(unsigned**)(object+0x138)))return;
if(CombatStatus_HasAilmentModeTwo(*(void**)(object+0x138)))return;
float base=(float)((Flags*)(*(char**)(p+0x64c)+0x14))->percent;
float amount=base*((float)(unsigned)(*(unsigned char*)(*(char**)(object+0x138)+0x4d))/100.0f);
if(amount>100.0f)amount=100.0f;
BattleAI_CacheActionPolicyEntry(p,1);
SubmitPercentScaledDisplayRecord(p,amount,2);
}
