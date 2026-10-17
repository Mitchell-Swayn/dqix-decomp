#include <globaldefs.h>
#include <Resource/ResourceMutex.h>
extern "C" {
    void *GetGlobalStatePointer();
    bool TestWordMaskNonzero(void *,int);
    void func_020dbae0(void *);
// Original: arm9/main @ 0x020DBC0C; symbol: func_020dbc0c; size: 0x3C.
    void RunConditionalUpdateWithResourceMutexTemporarilyDisabled(void *p){
        bool old=SetResourceMutexOperational(false);
        if(!TestWordMaskNonzero(GetGlobalStatePointer(),256))func_020dbae0(p);
        SetResourceMutexOperational(old);
    }
}
