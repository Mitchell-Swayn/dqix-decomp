#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FE2C; symbol: func_ov000_0215fe2c; size: 0x38.
extern "C" void *Util_GetListNodeAtIndex(void *list, int index) {
    if (*(unsigned char *)((unsigned char *)list + 0x1F) <= index) return 0;
    void *node = *(void **)((unsigned char *)list + 8);
    int i = 0;
    while (i < index && node != 0) {
        node = *(void **)((unsigned char *)node + 4);
        i++;
    }
    return node;
}
