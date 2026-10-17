#include <globaldefs.h>
ARM
extern "C" unsigned *func_ov001_02158dcc(void *object);
// Original: arm9/ov001 @ 0x0215905C; symbol: func_ov001_0215905c; size: 0x20.
extern "C" void func_ov001_0215905c(void *object, unsigned value) {
    unsigned *p = func_ov001_02158dcc(object);
    if (p) {
        p[0] = 7;
        *(unsigned *)((char *)p + 0x1c) = value;
    }
}
