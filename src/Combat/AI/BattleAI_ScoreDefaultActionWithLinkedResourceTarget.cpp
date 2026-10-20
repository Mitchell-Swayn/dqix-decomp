#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(...);
extern "C" int _fgr(...);
extern "C" int BattleAI_ScoreActionEffectsAndRankChoices(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021FCEB0; symbol: SubmitWeightedRequestWhenLinkedResourceExists.
extern "C" void BattleAI_ScoreDefaultActionWithLinkedResourceTarget(char*self){
int phase=B(self,6);float weight=1000.f;int ready;if(phase==2)ready=1;else{if(phase==0)return;ready=1;if(W(self,12)>=4)weight=50.f;}if(!ready)return;if(!BattleAI_SelectEnabledActionPolicyEntry(self,18))return;if(*(float*)(P(self,0)+0x8e3c)>1.01f)return;int found=0;for(int i=0;i<W(self,156);i++){char*record=P(P(self+4*i,124),0x148);if(record&&P(record,8)){found=1;break;}}if(!found)return;char request[200];memset(request,0,200);*(float*)(request+196)=weight;BattleAI_ScoreActionEffectsAndRankChoices(self,request,0,0);
}
