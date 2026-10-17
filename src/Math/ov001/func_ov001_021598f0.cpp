#include <globaldefs.h>
ARM
extern "C" int fix32_Divide(int num, int denom);
// Original: arm9/ov001 @ 0x021598F0; symbol: func_ov001_021598f0; size: 0x7C.
extern "C" int func_ov001_021598f0(void *arg0, unsigned char *arg1) {
    int limit = *(int *)((char *)arg0 + 0x14);
    int progress = *(int *)(arg1 + 0x68);
    if (progress >= limit) {
        *(int *)(arg1 + 0x90) = *(int *)((char *)arg0 + 0x10);
        *(int *)(arg1 + 0x68) = 0;
        return 0;
    }
    if (progress <= 0) {
        int delta = *(int *)((char *)arg0 + 0x10) - *(int *)(arg1 + 0x90);
        if (limit == 0)
            return 0;
        *(int *)(arg1 + 0x118) = fix32_Divide(delta, limit << 12);
    } else {
        *(int *)(arg1 + 0x90) += *(int *)(arg1 + 0x118);
    }
    *(int *)(arg1 + 0x68) += 1;
    return 1;
}
