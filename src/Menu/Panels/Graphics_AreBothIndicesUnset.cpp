#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F21F4; symbol: func_ov023_021f21f4; size: 0x38.
extern "C" int Graphics_AreBothIndicesUnset(void *p) {
    int first = *(int *)((char *)p + 0x60) == -1;
    int second = *(int *)((char *)p + 0x64) == -1;
    int both = first & second;
    return both != 0 ? 1 : 0;
}
