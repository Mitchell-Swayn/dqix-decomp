#include <globaldefs.h>
extern "C" {
    void *Network_GetConnectionManager();
    int Network_IsSessionActive(void *);
    unsigned char *NetworkOwnership_FindEntryByKey(void *,int);
    int Network_GetLocalMemberId(void *);
    void NetworkOwnership_ClearEntry(void *);
// Original: arm9/main @ 0x020E3468; symbol: func_020e3468; size: 0x54.
    void NetworkOwnership_ClearLocalEntry(void *p,int id){
        void *state=Network_GetConnectionManager();
        if(!Network_IsSessionActive(state))return;
        unsigned char *q=NetworkOwnership_FindEntryByKey(p,id);
        if(!q)return;
        if(q[0]!=Network_GetLocalMemberId(state))return;
        NetworkOwnership_ClearEntry(q);
    }
}
