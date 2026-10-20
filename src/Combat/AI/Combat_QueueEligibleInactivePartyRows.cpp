#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(void*,void*,int,unsigned char);
// Original: arm9/ov024 @ 0x021fcc6c; symbol: Combat_QueueEligibleInactivePartyRows; size 0x110.
extern "C" void Combat_QueueEligibleInactivePartyRows(void* self){unsigned weight=0x447a0000;int enabled;if(B(self,6)==2)enabled=1;else {if(B(self,6)==0)return;enabled=1;if(W(self,12)>=4)weight=0x42480000;}if(enabled&&BattleAI_SelectEnabledActionPolicyEntry(self,18)){unsigned data[50];for(int i=0;i<W(self,0x9c);i++){void* p=P((char*)self+4*i,0x7c);int slot=B(p,0x17c);if(slot>=0&&slot<3){void* rec=P(p,0x148);if(!rec)return;if(H(rec,4)){char* row=P(self,0)+0x81b4+24*slot;if(!B(row,22)&&!B(row,23)){memset(data,0,200);data[49]=weight;BattleAI_ScoreActionEffectsAndRankChoices(self,data,B(p,0x17c),(unsigned char)S(p,4));}}}}}}
