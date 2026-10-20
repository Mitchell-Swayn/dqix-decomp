#include <globaldefs.h>

extern "C" void WaitForStateThreeThenProcessOwnerWithTimeout(void*);

// Original: arm9/main @ 0x0202C7A8; symbol: func_0202c7a8; size: 0x14.
extern "C" ARM void* Network_DestroyConnectionManager(void* object) {
    WaitForStateThreeThenProcessOwnerWithTimeout(object);
    return object;
}
