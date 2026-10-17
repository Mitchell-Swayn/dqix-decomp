#pragma optimization_level 4
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02027AD8; symbol: func_02027ad8; size: 0x38.
    void GameState_FillFiveHundredTwelveByteRangeWithZeroOrFF(void *p,int flag){
        unsigned char *state=(unsigned char *)GameState::GetInstance();
        state+=0x3cc;
        state+=0x6c00;
        if(flag)memset(state,255,512);
        else memset(state,0,512);
    }
}
