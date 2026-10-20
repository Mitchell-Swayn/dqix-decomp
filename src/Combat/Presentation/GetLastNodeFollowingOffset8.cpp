#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021DF5CC; symbol: func_ov025_021df5cc; size: 0x18.
extern "C" void *GetLastNodeFollowingOffset8(void *node) {
    void *next;
    while ((next = *(void **)((char *)node + 8)) != 0)
        node = next;
    return node;
}
