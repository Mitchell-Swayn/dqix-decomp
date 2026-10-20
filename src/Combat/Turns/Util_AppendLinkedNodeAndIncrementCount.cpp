#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FE00; symbol: func_ov000_0215fe00; size: 0x2C.
extern "C" void Util_AppendLinkedNodeAndIncrementCount(void *object, void *node) {
    void **link = (void **)((char *)object + 8);
    while (*link)
        link = (void **)((char *)*link + 4);
    *link = node;
    ++*(unsigned char *)((char *)object + 0x1f);
}
