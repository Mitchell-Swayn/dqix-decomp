#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215996C; symbol: func_ov001_0215996c; size: 0x24.
extern "C" int func_ov001_0215996c(void *limitObject, void *state) {
    int current = *(int *)((unsigned char *)state + 0x60);
    int limit = *(int *)((unsigned char *)limitObject + 0x10);
    if (current >= limit) {
        *(int *)((unsigned char *)state + 0x60) = 0;
        return 0;
    }
    *(int *)((unsigned char *)state + 0x60) = current + 1;
    return 1;
}
