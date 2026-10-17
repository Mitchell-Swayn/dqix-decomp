#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020AC4C0; symbol: func_020ac4c0; size: 0x38.
    bool GameState_CopyB0ByteStateBufferToOutput(void *out){
        memset(out,0,0xb0);
        char *state=(char *)GameState::GetInstance()+0x7504;
        memcpy(out,state+0x3c,0xb0);
        return true;
    }
}
