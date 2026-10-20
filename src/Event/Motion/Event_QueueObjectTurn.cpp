#include <globaldefs.h>
ARM
extern "C" void* Pool_AppendAllocatedNode(void* pool);
extern "C" void* memcpy(void*, const void*, unsigned);
// Original: arm9/ov001 @ 0x0215A480; symbol: func_ov001_0215a480; size: 0x48.
extern "C" void Event_QueueObjectTurn(void* pool, unsigned first, unsigned second, unsigned third, unsigned fourth, unsigned fifth) {
    unsigned* node = (unsigned*)Pool_AppendAllocatedNode(pool);
    if (!node)
        return;
    node[0] = 8;
    memcpy(node + 1, &first, 12);
    node[4] = fourth;
    node[5] = fifth;
}
