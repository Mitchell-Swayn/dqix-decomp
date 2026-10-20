#include <globaldefs.h>
#include <Resource/ResourceMutex.h>
extern "C" {
    void *SystemState_GetGlobalFlags();
    bool SystemState_TestAnyFlags(void *,int);
    void DisplayOverlay_UpdateActivationAndScreen(void *);
// Original: arm9/main @ 0x020DBC0C; symbol: func_020dbc0c; size: 0x3C.
    void RunConditionalUpdateWithResourceMutexTemporarilyDisabled(void *p){
        bool old=SetResourceMutexOperational(false);
        if(!SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),256))DisplayOverlay_UpdateActivationAndScreen(p);
        SetResourceMutexOperational(old);
    }
}
