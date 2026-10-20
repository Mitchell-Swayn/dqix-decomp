#include <globaldefs.h>
extern "C" {
    bool Network_IsClientSession(void *);
    int Network_FindWirelessSlotByMemberId(void *,int);
// Original: arm9/main @ 0x0202C718; symbol: func_0202c718; size: 0x40.
    void Network_ClearMemberDisconnectNoticeQueued(unsigned char *p,int id){
        if(Network_IsClientSession(p))return;
        int i=Network_FindWirelessSlotByMemberId(p,id);
        p[0x1010]&=~(1<<i);
    }
}
