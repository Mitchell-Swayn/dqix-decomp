#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158338; symbol: func_ov001_02158338; size: 0x10.
extern "C" int func_ov001_02158338(void *a, void *b) {
    *(int *)((char *)b + 0x2e0) = *(int *)((char *)a + 0x1c);
    return 0;
}
