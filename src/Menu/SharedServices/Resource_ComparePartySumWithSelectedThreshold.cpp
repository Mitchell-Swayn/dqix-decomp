#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(void*,int);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" int Menu_GetSelectedGridIndex(void*);
// Original data: arm9/ov004 @ 0x216fff8; symbol: data_ov004_0216fff8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0300.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes[];
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void*,void*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original: arm9/ov004 @ 0x02168318; symbol: Resource_ComparePartySumWithSelectedThreshold; size: 0xb4.
// Compares summed party attribute5617 against selected threshold row and dispatches130 or132.
extern "C" int Resource_ComparePartySumWithSelectedThreshold(void* self) {
 int sum=SumIndexedValuesAcrossPresentPartyIds(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0x5617);void* record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),14);if(!record)return 0;if(MenuRecord_GetType(record)!=7)return 0;
 int index=Menu_GetSelectedGridIndex(record);unsigned char* threshold=0;if(index>=0&&index<6)threshold=MiniMedalMenuExchangeForSelectedReward_UnknownRoleInitializedBytes+4*index;
 PopulateOwnerThresholdSlotsAndResourceText(self,threshold);if(threshold&&sum>=*(short*)threshold)Menu_QueueScriptEntry(self,130);else Menu_QueueScriptEntry(self,132);return 0;
}
