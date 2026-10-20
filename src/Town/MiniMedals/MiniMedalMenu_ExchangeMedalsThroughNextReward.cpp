#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x2170012; symbol: data_ov004_02170012.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1a5608007f300d0026351200f03219005e3f2000314e2800853332005e463e009b2f5000fe33.
// Observed span: 38 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameState_GetIndexList(void*);void GameState_ComputeNextThresholdAndPartyContribution(short*,short*,short*,unsigned char*,int*);int GameState_ApplyPartyKeySideEffectsAndIncrementCount(void*,int);int MiniMedalMenu_AwardItemThroughPlacementState(void*,int);extern short MiniMedalMenuExchangeMedalsThroughNextReward_UnknownRoleInitializedBytes[];}
// Original: arm9/ov004 @ 0x02167ADC; symbol: ApplyPartyContributionUpToNextThreshold; size: 0x9c.
// Clamps party contribution at next threshold and applies tier placement on crossing.
extern "C" int MiniMedalMenu_ExchangeMedalsThroughNextReward(void* self){GameState_GetIndexList(_ZN9GameState11GetInstanceEv());short current,contribution,next;unsigned char reached;int tier;GameState_ComputeNextThresholdAndPartyContribution(&current,&contribution,&next,&reached,&tier);if(tier>=0){if(current+contribution>=next){GameState_ApplyPartyKeySideEffectsAndIncrementCount(self,(short)(next-current));MiniMedalMenu_AwardItemThroughPlacementState(self,MiniMedalMenuExchangeMedalsThroughNextReward_UnknownRoleInitializedBytes[tier*2]);}else GameState_ApplyPartyKeySideEffectsAndIncrementCount(self,contribution);}return 0;}
