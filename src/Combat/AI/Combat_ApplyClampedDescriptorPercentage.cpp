#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
struct Descriptor {char pad[20];unsigned low:7;unsigned rate:7;unsigned high:18;};
extern "C" int CombatStatus_CanReceiveEvaluatedDescriptorEffect(LinkedDescriptorView*);
extern "C" bool CombatStatus_CanApplyConfusion(unsigned*);
extern "C" int CombatEffect_TargetHasConfusion(void*);
extern "C" void BattleAI_CacheActionPolicyEntry(void*,int);
extern "C" void SubmitPercentScaledDisplayRecord(void*,float,int);
// Original: arm9/ov024 @ 0x021FD5C4; symbol: func_ov024_021fd5c4; size: 0xA8.
extern "C" void Combat_ApplyClampedDescriptorPercentage(char* self) {
char* object=*(char**)(self+0x668);
if(!CombatStatus_CanReceiveEvaluatedDescriptorEffect((LinkedDescriptorView*)object)) return;
if(!CombatStatus_CanApplyConfusion(*(unsigned**)(object+0x138))) return;
if(CombatEffect_TargetHasConfusion(object)) return;
float rate=(float)(*(Descriptor**)(self+0x64c))->rate;
rate*=((float)*(unsigned char*)(*(char**)(object+0x138)+0x4a))/100.0f;
if(rate>100.0f) rate=100.0f;
BattleAI_CacheActionPolicyEntry(self,1);
SubmitPercentScaledDisplayRecord(self,rate,7);
}
