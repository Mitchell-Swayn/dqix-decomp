#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
extern "C" {
// Original: arm9/main @ 0x020ABF38; symbol: func_020abf38; size: 0x28.
int GameState_Copy4D0ByteStateBufferToOutput(void *p){memcpy(p,(char *)GameState::GetInstance()+0x75f0,0x4d0);return 1;}
}
