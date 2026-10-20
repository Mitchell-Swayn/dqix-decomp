#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);
extern "C" int BattleAI_TestTargetSecondaryStatusFlag10(void*);
extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(void*,void*,int,int);
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov024 @ 0x021FCD7C; symbol: Combat_SubmitDefaultDescriptorForEligibleActor; size: 0x98.
extern "C" void Combat_SubmitDefaultDescriptorForEligibleActor(char* self) {
 int eligible=0;unsigned mode=*(unsigned char*)(self+6);if(mode==2)eligible=1;if(!mode)return;if(*(int*)(self+12)>=3)eligible=1;if(!eligible)return;
 if(!BattleAI_SelectEnabledActionPolicyEntry(self,18))return;if(BattleAI_TestTargetSecondaryStatusFlag10(*(void**)(self+8)))return;
 char desc[200];memset(desc,0,200);*(float*)(desc+196)=1000.0f;BattleAI_ScoreActionEffectsAndRankChoices(self,desc,0,*(short*)(self+4)&255);
}
