#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" char* GameState_GetIndexList(GameState*);extern "C" unsigned Script_ReadParameterAsInteger(char*);extern "C" void Script_WriteIntegerReferenceOutput(char*,unsigned);extern "C" unsigned Inventory_GetItemCount(char*,int);
// Original: arm9/main @ 0x0209D9C4; symbol: func_0209d9c4; size: 0x44.
extern "C" int Script_ReadSpecialInventoryItemCount(char* p){char* state=GameState_GetIndexList(GameState::GetInstance());int id=Script_ReadParameterAsInteger(p);unsigned value=Inventory_GetItemCount(state+0xe04,(short)id);Script_WriteIntegerReferenceOutput(p+8,value);return 1;}
