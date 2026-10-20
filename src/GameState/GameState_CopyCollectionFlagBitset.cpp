#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x020AC460; symbol: func_020ac460; size: 0x34.
int GameState_CopyCollectionFlagBitset(void *p){memset(p,0,0x3c);memcpy(p,(char *)GameState::GetInstance()+0x7504,0x3c);return 1;}
}
