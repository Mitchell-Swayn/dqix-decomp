#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
extern "C" {
int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x02085F1C; symbol: func_02085f1c; size: 0x98.
int GameState_SumTypeThreeFlags55And59And62(unsigned char *p,int type){if(type<0){if(*(short *)(p+0x2ac)>0)type=(*(unsigned int *)(p+0x29c)<<23)>>27;else type=33;}GameState *state=GameState::GetInstance();int count=0;if(type==3){if(p[0x8f2]&128)count+=GameState_ReadAttributeBits12To19(state,55);if(p[0x8f3]&8)count+=GameState_ReadAttributeBits12To19(state,59);if(p[0x8f3]&64)count+=GameState_ReadAttributeBits12To19(state,62);}return count;}
}
