#include <globaldefs.h>
ARM
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(short*,short*,short*,unsigned char*,int* volatile);
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void*,int);
extern "C" void MiniMedalMenu_ExchangeMedalsThroughNextReward(void*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original: arm9/ov004 @ 0x02167F1C; symbol: ChoosePartyThresholdTransition; size: 0x94.
// Computes party threshold and chooses transition40,60 or50 from reached flag and signed tier.
extern "C" int MiniMedalMenu_ExchangeAndChooseRewardOrExhausted(void* p){
 int tier;short current,contribution,next;unsigned char reached;
 GameState_ComputeNextThresholdAndPartyContribution(&current,&contribution,&next,&reached,&tier);
 PopulateOwnerThresholdSlotsAndResourceText(p,0);MiniMedalMenu_ExchangeMedalsThroughNextReward(p);
 if(reached)Menu_QueueScriptEntry(p,40);
 else if(tier<0)Menu_QueueScriptEntry(p,60);
 else {PopulateOwnerThresholdSlotsAndResourceText(p,0);Menu_QueueScriptEntry(p,50);}return 0;
}
