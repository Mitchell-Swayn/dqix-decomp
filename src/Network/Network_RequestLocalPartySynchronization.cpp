#include <globaldefs.h>
extern "C" {
    void *Network_GetConnectionManager();
    bool Network_IsSessionActive(void *);
    bool Network_IsParentOrOffline(void *);
    void Network_QueuePartyAction(int,int);
// Original: arm9/main @ 0x020E36F0; symbol: func_020e36f0; size: 0x58.
    void Network_RequestLocalPartySynchronization(unsigned char *p){
        void *state=Network_GetConnectionManager();
        if(!Network_IsSessionActive(state))return;
        if(Network_IsParentOrOffline(state)){
            if(Network_IsSessionActive(Network_GetConnectionManager()))*p|=1;
            return;
        }Network_QueuePartyAction(0,0);
    }
}
