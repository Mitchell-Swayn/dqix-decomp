#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Descriptor{unsigned tag:12;unsigned rest:20;};extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);extern "C" void* memset(void*,int,unsigned);extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(void*,void*,int,int);extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void*,int);
// Original: arm9/ov024 @ 0x021FBF18; symbol: DispatchSpecialPackedIdentifierAction; size: 0xDC.
extern "C" void BattleAI_ScoreSpecialTensionOrRestrictionAction(char* self){unsigned tag=((Descriptor*)(P(self,0x64c)+4))->tag;if(tag==508||tag==527){unsigned state=B(self,6);int eligible=0;if(state==2)eligible=1;if(!state)return;if((int)W(self,12)>=3)eligible=1;if(!eligible)return;if(!BattleAI_SelectEnabledActionPolicyEntry(self,18))return;if(B(P(P(self,8),0x138),0x24)>=3)return;char request[200];memset(request,0,200);*(float*)(request+196)=1000.0f;BattleAI_ScoreActionEffectsAndRankChoices(self,request,0,0);}else if(BattleAI_SelectEnabledActionPolicyEntry(self,1))BattleAI_ScoreHostileAilmentAndDebuffTargets(self,8);}
