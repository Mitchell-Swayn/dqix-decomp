#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    extern short data_020e8a9e[];
    bool Object_ReadIndexedBitAtOffset8EC(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x02086314; symbol: func_02086314; size: 0x6C.
    int GameState_SumEnabledFlags80Through261Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=data_020e8a9e[i])!=-1){
            if(Object_ReadIndexedBitAtOffset8EC(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
