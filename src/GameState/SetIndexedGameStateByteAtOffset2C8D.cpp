#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
extern "C" {
char *GameState_GetIndexList();
// Original: arm9/main @ 0x0203970C; symbol: func_0203970c; size: 0x24.
void SetIndexedGameStateByteAtOffset2C8D(int unused,int i,unsigned char v){GameState::GetInstance();char *p=GameState_GetIndexList();*(unsigned char *)(p+i+0x2c8d)=v;}
}
