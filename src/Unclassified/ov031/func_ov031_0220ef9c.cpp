#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e540[];
// Original: arm9/ov031 @ 0x0220EF9C; symbol: func_ov031_0220ef9c; size: 0x34.
extern "C" void func_ov031_0220ef9c(void *obj) {
    unsigned int callback = *(unsigned int *)(data_ov031_0224e540 + 0x28);
    if (callback != 0) {
        ((void (*)(void *, void *, void *, int))callback)((char *)obj + 0x1e, (char *)obj + 0x18, (char *)obj + 0x2c, *(unsigned short *)((char *)obj + 6));
    }
}
