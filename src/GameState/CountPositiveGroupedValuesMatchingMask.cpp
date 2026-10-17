#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" unsigned char* GameState_GetIndexList();extern "C" short* ReadValueForIndexThroughSeven(void*,int);extern "C" int Object_ReadBoundedSlotGroupHalfwordCount(void*,int);extern short data_020f29dc[];
// Original: arm9/main @ 0x020DD300; symbol: func_020dd300; size: 0xCC.
extern "C" int CountPositiveGroupedValuesMatchingMask(unsigned mask){GameState::GetInstance();unsigned char* state=GameState_GetIndexList();short* values=ReadValueForIndexThroughSeven(state+0x1d4,0);int count=Object_ReadBoundedSlotGroupHalfwordCount(state+0x1d4,0);short matches=0;for(short i=0;i<count;i++){int value=values[i];if(value>0){value=(short)(value-value%100);for(unsigned char j=0;j<12;j++){if((mask&(1<<j)) && value==data_020f29dc[j]){matches++;break;}}}}return matches;}
