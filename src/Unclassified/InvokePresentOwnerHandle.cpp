#include <globaldefs.h>

extern "C" void func_02057334(void*);
struct HandleOwner { char unknown[0x4]; void* handle; };

// Original: arm9/main @ 0x02055774; symbol: func_02055774; size: 0x18.
extern "C" ARM void InvokePresentOwnerHandle(HandleOwner* owner) {
    if (owner->handle)
        func_02057334(owner->handle);
}
