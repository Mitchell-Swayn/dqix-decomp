#include "System/RuntimeState.h"

#pragma optimize_for_size off
#pragma dont_inline on
// Original: arm9/main @ 0x0200EDF4; symbol: func_0200edf4; size: 0x44.
extern "C" void RuntimeDestructors_DestroyRegisteredObjects()
{
    RuntimeDestructorNode* node = RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
    if (node) {
        do {
            RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage = node->next;
            node->destroy(node->object, -1);
            node = RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
        } while (node);
    }
}
