#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#include <std_library_functions.h>
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(char*,int);extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(char*,void*,int,unsigned);
// Original: arm9/ov024 @ 0x021FCE14; symbol: DispatchInitialDescriptorActionWithThousandScale; size: 0x9c.
extern "C" void BattleAI_ScoreTensionActionOnlyAtBaseTension(char* self){
int enabled=0;if(B(self,6)==2)enabled=1;if(!B(self,6))return;if(W(self,12)>=3)enabled=1;if(!enabled)return;if(!BattleAI_SelectEnabledActionPolicyEntry(self,18))return;if(B(P(P(self,8),0x138),0x24)>=1)return;char action[200];memset(action,0,200);*(float*)(action+196)=1000.f;BattleAI_ScoreActionEffectsAndRankChoices(self,action,0,*(short*)(self+4)&255);
}
