#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
extern "C" {
char *GameState_GetIndexList();
// Original: arm9/main @ 0x02039768; symbol: func_02039768; size: 0x28.
void GameState_CopySevenBytesToIndexedStorage(int unused,void *q){GameState::GetInstance();memcpy(GameState_GetIndexList()+0x2c8d,q,7);}
}
