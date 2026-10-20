#include <globaldefs.h>
extern "C" {
    void *Network_GetConnectionManager();
    bool Network_IsSessionActive(void *);
    int Network_GetLocalMemberId(void *);
    void NetworkOwnership_RequestForPeer(void *,int,unsigned char);
// Original: arm9/main @ 0x020E3328; symbol: func_020e3328; size: 0x40.
    void NetworkOwnership_RequestForLocalPeer(void *p,int id){
        void *state=Network_GetConnectionManager();
        if(!Network_IsSessionActive(state))return;
        NetworkOwnership_RequestForPeer(p,id,Network_GetLocalMemberId(state));
    }
}
