#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" {
    struct Block{
        unsigned char bytes[1024];
        int count;
    };
// Original: arm9/main @ 0x020A9BA4; symbol: func_020a9ba4; size: 0x70.
    bool GameState_CopyTwo512ByteBuffersAndCount(const Block *input){
        unsigned char *state=(unsigned char *)GameState::GetInstance();
        Block local;
memcpy(&local,input,sizeof(local));
        memcpy(state+0x6180,local.bytes+512,512);
        memcpy(state+0x5f80,local.bytes,512);
        *(int *)(state+0x5f7c)=local.count;
        return true;
    }
}
