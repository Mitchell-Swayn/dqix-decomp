#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
// Original: arm9/main @ 0x02026B7C; symbol: func_02026b7c; size: 0x4C.
    void SetBitsForPresentFirstFourGameObjects(unsigned char *p){
        GameState *state=GameState::GetInstance();
        p+=0x96;
        for(int i=0;i<4;i++)if(state->GetGameObjectByIndex(i))p[0xa00]|=1<<i;
    }
}
