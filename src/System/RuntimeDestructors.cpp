#include "System/RuntimeState.h"

#pragma optimize_for_size off
#pragma dont_inline on
// Original: arm9/main @ 0x0200EDF4; symbol: func_0200edf4; size: 0x44.
extern "C" void RuntimeDestructors_DestroyRegisteredObjects()
{
    RuntimeDestructorNode* node = data_020f33b0;
    if (node) {
        do {
            data_020f33b0 = node->next;
            node->destroy(node->object, -1);
            node = data_020f33b0;
        } while (node);
    }
}
