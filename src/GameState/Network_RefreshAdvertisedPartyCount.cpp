#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    void GameState_CollectPresentIndicesAmongFirstFour(GameState *,int *,int *);
// Original: arm9/main @ 0x0202C3E0; symbol: func_0202c3e0; size: 0x30.
    void Network_RefreshAdvertisedPartyCount(unsigned char *p){
        int values[4];
        int out;
        GameState_CollectPresentIndicesAmongFirstFour(GameState::GetInstance(),values,&out);
        p[0x1027]=out;
    }
}
