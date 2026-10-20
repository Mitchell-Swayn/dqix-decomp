#include <globaldefs.h>
#include <GameState/GameState.h>
// Original: arm9/main @ 0x02092CD0; symbol: func_02092cd0; size: 0x48.
extern "C" int GameState_CountMatchingFourPlacementBytes(int unused, unsigned int value) {
    GameState* state=GameState::GetInstance();
    unsigned char count=0;
    unsigned int index=0;
    while (index<4) {
        if (value==*(unsigned char*)((char*)state+0x7f76+index))
            count=(unsigned char)(count+1);
        index=(index+1)&0xff;
    }
    return count;
}
