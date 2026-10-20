#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x20f29dc; symbol: data_020f29dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 204e1450384ab04f4c4f78504051844ee84e9c4adc50a451.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* GameState_GetIndexList();extern "C" short* Inventory_GetGroupItemIds(void*,int);extern "C" int Inventory_GetGroupCapacity(void*,int);extern short CountPositiveGroupedValuesMatchingMask_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020DD300; symbol: func_020dd300; size: 0xCC.
extern "C" int CountPositiveGroupedValuesMatchingMask(unsigned mask){GameState::GetInstance();unsigned char* state=GameState_GetIndexList();short* values=Inventory_GetGroupItemIds(state+0x1d4,0);int count=Inventory_GetGroupCapacity(state+0x1d4,0);short matches=0;for(short i=0;i<count;i++){int value=values[i];if(value>0){value=(short)(value-value%100);for(unsigned char j=0;j<12;j++){if((mask&(1<<j)) && value==CountPositiveGroupedValuesMatchingMask_UnknownRoleInitializedBytes[j]){matches++;break;}}}}return matches;}
