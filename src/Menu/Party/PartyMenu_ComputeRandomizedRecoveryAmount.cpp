#include <globaldefs.h>
#include "GameState/GameState.h"
#include <Util/Random.h>
#include <Combat/Main/CombatCalculations.h>
ARM
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*, int);
struct AmountRangeWord {unsigned prefix:8;unsigned jitter:10;unsigned suffix:14;};
struct AmountBoundsWord {unsigned prefix:10;unsigned low:10;unsigned high:10;unsigned suffix:2;};
struct AmountParameters {AmountRangeWord range;AmountBoundsWord bounds;};
struct ActionThresholdWord {unsigned prefix:12;unsigned low:10;unsigned high:10;};
struct ActionKindWord {unsigned prefix:16;unsigned kind:2;unsigned suffix:14;};
struct ActionAmountRecord {unsigned first;ActionThresholdWord threshold;unsigned unused[2];unsigned flags;unsigned unused14;ActionKindWord type;};
struct MemberAmountWord {unsigned prefix:20;unsigned value:10;unsigned suffix:2;};
// Original: arm9/ov002 @ 0x021538E4; symbol: func_ov002_021538e4; size: 0x2FC.
// Samples packed amount bounds with additive jitter; flagged kind2 actions interpolate using a party member stat.
extern "C" int PartyMenu_ComputeRandomizedRecoveryAmount(void* unused,ActionAmountRecord* action,AmountParameters* parameters,int memberIndex) {
 Random* random=GetBTRandom();float result=0;
 if(parameters) {
  if(action->type.kind==2) {
   GameObject* memberObject=GameState_GetObjectWithFlag100(GameState::GetInstance(),memberIndex);
   if(!memberObject)return 0;
   char* member=(char*)memberObject;
   if(action->flags&0x8000) {
    unsigned short stat=(unsigned short)((MemberAmountWord*)(*(char**)(member+0x134)+0x3c))->value;
    if(stat<=action->threshold.low) {
     unsigned jitter=parameters->range.jitter;
     result=(float)parameters->bounds.low+NextRandomFloatBetween(random,-1.0f*(float)jitter,(float)jitter);
    } else if(stat>=action->threshold.high) {
     unsigned jitter=parameters->range.jitter;
     result=(float)parameters->bounds.high+NextRandomFloatBetween(random,-1.0f*(float)jitter,(float)jitter);
    } else {
     float fraction=(float)(parameters->bounds.high-parameters->bounds.low)/(float)(action->threshold.high-action->threshold.low);
     unsigned center=(int)(fraction*(float)(stat-action->threshold.low))+parameters->bounds.low;
     float base=(float)center;
     unsigned jitter=parameters->range.jitter;
     result=base+NextRandomFloatBetween(random,-1.0f*(float)jitter,(float)jitter);
    }
   } else {
    float base=NextRandomFloatBetween(random,(float)parameters->bounds.low,(float)parameters->bounds.high);
    unsigned jitter=parameters->range.jitter;
    result=base+NextRandomFloatBetween(random,-1.0f*(float)jitter,(float)jitter);
   }
  } else {
   float base=NextRandomFloatBetween(random,(float)parameters->bounds.low,(float)parameters->bounds.high);
   unsigned jitter=parameters->range.jitter;
   result=base+NextRandomFloatBetween(random,-1.0f*(float)jitter,(float)jitter);
  }
 }
 return RoundUp(result);
}
