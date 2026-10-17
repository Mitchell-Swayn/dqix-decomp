#include <globaldefs.h>
ARM
extern "C" unsigned *Pool_AllocateAndLinkNode(void *object);
// Original: arm9/ov001 @ 0x0215A530; symbol: func_ov001_0215a530; size: 0x20.
extern "C" void func_ov001_0215a530(void *object, unsigned value) {
    unsigned *p = Pool_AllocateAndLinkNode(object);
    if (p) {
        p[0] = 9;
        *(unsigned *)((char *)p + 0x10) = value;
    }
}
