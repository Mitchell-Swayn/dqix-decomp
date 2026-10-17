#include <globaldefs.h>

extern "C" void func_0202aec0(void*);

// Original: arm9/main @ 0x0202C794; symbol: func_0202c794; size: 0x14.
extern "C" ARM void* FinalizeObjectAndReturnPointer(void* object) {
    func_0202aec0(object);
    return object;
}
