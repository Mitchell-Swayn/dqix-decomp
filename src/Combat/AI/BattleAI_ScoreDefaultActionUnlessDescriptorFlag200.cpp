#include <globaldefs.h>
ARM
extern "C" {int BattleAI_SelectEnabledActionPolicyEntry(void*,unsigned);int Combatant_HasMPCostExemption(void*);void* memset(void*,int,unsigned);void BattleAI_ScoreActionEffectsAndRankChoices(void*,void*,int,unsigned);}
// Original: arm9/ov024 @ 0x021FCBC8; symbol: SubmitDefaultDescriptorWhenEntryEligible; size: 0xa4.
// Submits zeroed200-byte descriptor with default1000 float when entry flags permit.
extern "C" void BattleAI_ScoreDefaultActionUnlessDescriptorFlag200(unsigned char* self){int eligible=0;if(self[6]==2)eligible=1;if(!self[6])return;if(*(int*)(self+12)>=3)eligible=1;if(!eligible || !BattleAI_SelectEnabledActionPolicyEntry(self,18) || *(int*)(self+12)<=1 || Combatant_HasMPCostExemption(*(void**)(self+8)))return;unsigned descriptor[50];memset(descriptor,0,200);descriptor[49]=0x447a0000;BattleAI_ScoreActionEffectsAndRankChoices(self,descriptor,0,*(short*)(self+4)&255);}
