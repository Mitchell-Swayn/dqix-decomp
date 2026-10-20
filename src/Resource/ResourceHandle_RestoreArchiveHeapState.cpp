#include <globaldefs.h>

extern "C" void CleanupAllocatorGroupsUntilRequestedState(void*, int);
struct HandleOwner { void* handle; };

// Original: arm9/main @ 0x0203AA80; symbol: func_0203aa80; size: 0x18.
extern "C" ARM void ResourceHandle_RestoreArchiveHeapState(HandleOwner* owner, int state) {
    if (owner->handle)
        CleanupAllocatorGroupsUntilRequestedState(owner->handle, state);
}
