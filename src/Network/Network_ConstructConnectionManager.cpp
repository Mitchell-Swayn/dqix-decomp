#include <globaldefs.h>

extern "C" void Network_ResetConnectionManager(void*);

// Original: arm9/main @ 0x0202C794; symbol: func_0202c794; size: 0x14.
extern "C" ARM void* Network_ConstructConnectionManager(void* object) {
    Network_ResetConnectionManager(object);
    return object;
}
