#include <globaldefs.h>
extern "C" {
    void *Network_GetConnectionManager();
    bool Network_IsSessionActive(void *);
    unsigned char *NetworkOwnership_FindEntryByKey(void *,int);
    void NetworkOwnership_ClearEntry(void *);
    bool Network_IsClientSession(void *);
    int Network_GetLocalMemberId(void *);
    void NetworkOwnership_QueuePeerRequestChange(int,unsigned char,unsigned char);
// Original: arm9/main @ 0x020E33B4; symbol: func_020e33b4; size: 0x74.
    void NetworkOwnership_ReleaseForPeer(void *p,int id,int value){
        void *state=Network_GetConnectionManager();
        if(!Network_IsSessionActive(state))return;
        unsigned char *q=NetworkOwnership_FindEntryByKey(p,id);
        if(!q)return;
        if(q[0]!=value)return;
        NetworkOwnership_ClearEntry(q);
        if(!Network_IsClientSession(state))return;
        int mode=Network_GetLocalMemberId(state);
        NetworkOwnership_QueuePeerRequestChange(0,id,mode);
    }
}
