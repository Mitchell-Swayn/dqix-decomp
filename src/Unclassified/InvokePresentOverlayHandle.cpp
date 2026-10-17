#include <globaldefs.h>

extern "C" void func_ov003_0217daa4(void*);
struct Owner { char unknown[12]; void* handle; };

// Original: arm9/main @ 0x020DAE80; symbol: func_020dae80; size: 0x18.
extern "C" ARM void InvokePresentOverlayHandle(Owner* object) {
    if(object->handle) func_ov003_0217daa4(object->handle);
}
