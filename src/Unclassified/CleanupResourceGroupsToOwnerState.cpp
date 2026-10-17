#include <globaldefs.h>

extern "C" void CleanupAllocatorGroupsUntilRequestedState(void*, int);
struct Owner { void* handle; char unknown[0x9c]; int state; };

// Original: arm9/main @ 0x0203AA44; symbol: func_0203aa44; size: 0x20.
extern "C" ARM void CleanupResourceGroupsToOwnerState(Owner* object) {
    if(object->handle) CleanupAllocatorGroupsUntilRequestedState(object->handle, object->state);
}
