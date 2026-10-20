#include <globaldefs.h>
extern "C" {
    void *Network_GetConnectionManager();
    bool Network_IsClientSession(void *);
// Original: arm9/main @ 0x0206E31C; symbol: func_0206e31c; size: 0x2C.
    bool Network_TestIdentifierAllowedInCurrentMode(void *p,int id){
        void *state=Network_GetConnectionManager();
        if(Network_IsClientSession(state)&&id<174)return false;
        return true;
    }
}
