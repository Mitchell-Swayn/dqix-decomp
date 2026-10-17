#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void* memset(void*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x020AC3C8; symbol: func_020ac3c8; size: 0x98.
extern "C" int GameState_MergePositiveIdsIntoBitset(unsigned* out,const short* ids,int count) {
    memset(out,0,60);
    char* state=(char*)GameState::GetInstance()+0x104;
    memcpy(out,state+0x7400,60);
    for(int i=0;i<count;i++) {
        int id=ids[i];
        if(id>0) out[id/32]|=1u<<(id%32);
    }
    memcpy(state+0x7400,out,60);
    return 1;
}
