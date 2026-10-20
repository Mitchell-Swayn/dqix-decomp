#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" int Menu_GetSelectedGridIndex(void*);
extern "C" int GameState_ApplyPartyKeySideEffectsAndIncrementCount(void*,int);
extern "C" int MiniMedalMenu_AwardItemThroughPlacementState(void*,int);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original data: arm9/ov004 @ 0x216fff8; symbol: data_ov004_0216fff8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0300.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
// Original data: arm9/ov004 @ 0x216fffa; symbol: data_ov004_0216fffa.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 674605000156080040560a005b560f003c5614001243.
// Observed span: 22 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes[],MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov004 @ 0x02168400; symbol: ApplyTypeSevenPlacementTableAndSetState140; size: 0x8c.
extern "C" int MiniMedalMenu_ExchangeForSelectedReward(void* self){
void* entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),14);if(!entry)return 0;if(MenuRecord_GetType(entry)!=7)return 0;int index=Menu_GetSelectedGridIndex(entry);if(index>=0&&index<6){GameState_ApplyPartyKeySideEffectsAndIncrementCount(self,*(short*)(MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes+index*4));MiniMedalMenu_AwardItemThroughPlacementState(self,*(short*)(MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes_Variant2+index*4));}Menu_QueueScriptEntry(self,140);return 0;
}
