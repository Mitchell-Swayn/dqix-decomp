#include <globaldefs.h>
ARM
extern "C" unsigned int *Pool_AllocateAndAppendNode(void *pool);
// Original: arm9/ov001 @ 0x0215A674; symbol: Pool_AppendType16NodeWithTwoValues; size: 0x28.
// Appends a pool node, writes tag 0x16, and stores the two values at offsets 0x10 and 0x14.
extern "C" void Pool_AppendType16NodeWithTwoValues(void *pool, unsigned int first, unsigned int second) {
    unsigned int *node = Pool_AllocateAndAppendNode(pool);
    if (node) {
        node[0] = 0x16;
        *(unsigned int *)((unsigned char *)node + 0x10) = first;
        *(unsigned int *)((unsigned char *)node + 0x14) = second;
    }
}
