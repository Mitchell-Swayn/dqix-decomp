#include "System/RuntimeState.h"

// Original: arm9/main @ 0x0200EFD0; symbol: __register_global_object; size: 0x20.
extern "C" void __register_global_object(
    void* object, void (*destructor)(void*, int), RuntimeDestructorNode* node)
{
    node->next = RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
    node->destroy = destructor;
    node->object = object;
    RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage = node;
}
