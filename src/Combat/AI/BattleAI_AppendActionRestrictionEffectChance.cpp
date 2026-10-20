#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
struct DescriptorBits{unsigned id:12;unsigned remaining:20;};
extern "C" {int CombatStatus_CanReceiveEvaluatedDescriptorEffect(void*);int CombatStatus_CanApplyActionRestriction(void*,unsigned,int);int Combat_HasActionRestriction(void*);void BattleAI_CacheActionPolicyEntry(void*,int);void SubmitPercentScaledDisplayRecord(char*,float,unsigned char);}
// Original: arm9/ov024 @ 0x021FD1BC; symbol: Graphics_SubmitAllowedDescriptorPercent; size: 0xf8.
// Checks descriptor exclusions and operation flags then submits a clamped scaled percent.
extern "C" void BattleAI_AppendActionRestrictionEffectChance(unsigned char* self){unsigned char* object=P(self,0x668);if(!CombatStatus_CanReceiveEvaluatedDescriptorEffect(object))return;unsigned char* record=P(self,0x64c);if(!CombatStatus_CanApplyActionRestriction(P(object,0x138),(unsigned char)H(record,0x32),(unsigned short)((DescriptorBits*)(record+4))->id))return;if(Combat_HasActionRestriction(object))return;record=P(self,0x64c);if(H(record,0x30)==2&&(U(object,0)&0x400)&&P(object,0x144)&&(((unsigned)U(P(object,0x144),10)<<20)>>31))return;float percent=(float)(unsigned)(((unsigned)W(record,0x14)<<18)>>25);percent*=((float)(unsigned)P(object,0x138)[0x4c]/100.0f);if(percent>100.0f)percent=100.0f;BattleAI_CacheActionPolicyEntry(self,1);SubmitPercentScaledDisplayRecord((char*)self,percent,8);}
