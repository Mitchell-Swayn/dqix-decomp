#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    extern short data_020e8ae2[];
    bool Object_ReadIndexedBitAtOffset8EC(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x0208608C; symbol: func_0208608c; size: 0x6C.
    int GameState_SumEnabledFlags47Through280Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=data_020e8ae2[i])!=-1){
            if(Object_ReadIndexedBitAtOffset8EC(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
