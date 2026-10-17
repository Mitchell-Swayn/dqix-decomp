#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    extern short data_020e8ad2[];
    bool Object_ReadIndexedBitAtOffset8EC(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x020861D0; symbol: func_020861d0; size: 0x6C.
    int GameState_SumEnabledFlags78Through257Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=data_020e8ad2[i])!=-1){
            if(Object_ReadIndexedBitAtOffset8EC(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
