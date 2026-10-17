#include <globaldefs.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    bool IsFirstWordNonzero(void *);
    bool TestInactiveOrPrimaryIndexState(void *);
    void Network_QueuePartyAction(int,int);
// Original: arm9/main @ 0x020E36F0; symbol: func_020e36f0; size: 0x58.
    void SetPrimaryContextFlagOrInvokeOverlayAction(unsigned char *p){
        void *state=Object_GetGlobalConnectionState();
        if(!IsFirstWordNonzero(state))return;
        if(TestInactiveOrPrimaryIndexState(state)){
            if(IsFirstWordNonzero(Object_GetGlobalConnectionState()))*p|=1;
            return;
        }Network_QueuePartyAction(0,0);
    }
}
