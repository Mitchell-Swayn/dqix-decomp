#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02181C94; symbol: func_ov000_02181c94; size: 0x28.
extern "C" int Util_CopyLinkedListFieldToArray(void *, void *owner, int *out) {
    void *node = *(void **)((char *)owner + 0x14);
    int count = 0;
    while (node) {
        out[count] = *(short *)((char *)node + 0xe);
        node = *(void **)((char *)node + 0x20);
        ++count;
    }
    return count;
}
