#include <globaldefs.h>

extern "C" char* GameResources_GetInstance();
extern "C" void Object_TransitionByte9C1AndResetLoadState(void*, int);

// Original: arm9/main @ 0x020DC3B8; symbol: func_020dc3b8; size: 0x1C.
extern "C" ARM void SetGlobalDisplayOwnerStateTwo() {
    char* state=GameResources_GetInstance();
    Object_TransitionByte9C1AndResetLoadState(*(void**)(state+0x36d0), 2);
}
