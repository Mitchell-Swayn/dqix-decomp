#include <globaldefs.h>
ARM
extern "C" unsigned int *Pool_AllocateAndAppendNode(void);
// Original: arm9/ov001 @ 0x0215A510; symbol: func_ov001_0215a510; size: 0x20.
extern "C" void func_ov001_0215a510(void *unused, unsigned int value) {
    unsigned int *p = Pool_AllocateAndAppendNode();
    if (p) { p[0] = 0x14; *(unsigned int *)((unsigned char *)p + 0x10) = value; }
}
