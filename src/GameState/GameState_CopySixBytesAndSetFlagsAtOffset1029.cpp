#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    struct Bytes6{
        unsigned char bytes[6];
    };
// Original: arm9/main @ 0x0202C410; symbol: func_0202c410; size: 0x68.
    void GameState_CopySixBytesAndSetFlagsAtOffset1029(unsigned char *p){
        p[0x1029]|=72;
        unsigned char *state=(unsigned char *)GameState::GetInstance();
        Bytes6 local=*(Bytes6 *)(state+0x74fe);
        *(Bytes6 *)(p+0x102c)=local;
    }
}
