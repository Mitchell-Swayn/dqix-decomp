#include <globaldefs.h>

extern "C" void InvokeHandleStateWhenPresent(void*, int);
struct Owner { char unknown[0xb8]; int current; char reserved[4]; int saved; };

// Original: arm9/main @ 0x0205EB08; symbol: func_0205eb08; size: 0x1C.
extern "C" ARM void ResourceHandle_ApplyAndSaveCurrentState(Owner* object) {
    InvokeHandleStateWhenPresent(object, object->current);
    object->saved=object->current;
}
