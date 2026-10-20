#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    void *Network_GetConnectionManager();
    bool Network_IsClientSession(void *);
    bool Network_FindTaggedAcknowledgement(void *,int,int);
    unsigned char *Network_AcquireTaggedAcknowledgementEntry(void *);
    void QueueTaggedRecordOperationMessage34(int,unsigned char,int);
// Original: arm9/main @ 0x020E392C; symbol: func_020e392c; size: 0x68.
    void Network_InsertTaggedAcknowledgement(void *p,int id,int value){
        if(Network_IsClientSession(Network_GetConnectionManager()))return;
        if(Network_FindTaggedAcknowledgement(p,id,value))return;
        unsigned char *q=Network_AcquireTaggedAcknowledgementEntry(p);
        if(!q)return;
        GameState::GetInstance();
        q[4]=id;
        *(int *)q=value;
        QueueTaggedRecordOperationMessage34(3,id,value);
    }
}
