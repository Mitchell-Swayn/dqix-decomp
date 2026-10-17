#include <globaldefs.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    bool TestActiveWordAndGlobalStateNonzero(void *);
// Original: arm9/main @ 0x0206E31C; symbol: func_0206e31c; size: 0x2C.
    bool Network_TestIdentifierAllowedInCurrentMode(void *p,int id){
        void *state=Object_GetGlobalConnectionState();
        if(TestActiveWordAndGlobalStateNonzero(state)&&id<174)return false;
        return true;
    }
}
