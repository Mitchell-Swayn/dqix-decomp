#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int Inventory_TestItemConsumableFlag();extern "C" void* GameState_GetIndexList();extern "C" int Inventory_RemoveItemCountAndCompact(void*,int,int);extern "C" void GameState_CopyStatisticsRecord(void*);extern "C" void Statistics_AddFlaggedItemConsumptionCount(void*,int);extern "C" void GameState_StoreStatisticsRecord(void*);
// Original: arm9/main @ 0x020DDDCC; symbol: func_020dddcc; size: 0x70.
extern "C" ARM int Inventory_ConsumeSelectedItem(char* p){unsigned work[44];if(!Inventory_TestItemConsumableFlag())return 0;GameState::GetInstance();if(!Inventory_RemoveItemCountAndCompact(GameState_GetIndexList(),*(short*)(p+0x18),1))return 0;if(*(unsigned*)(p+8)>>31){GameState_CopyStatisticsRecord(work);Statistics_AddFlaggedItemConsumptionCount(work,1);GameState_StoreStatisticsRecord(work);}return 1;}
