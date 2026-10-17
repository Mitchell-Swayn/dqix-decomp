#include <globaldefs.h>
ARM
extern "C" unsigned int *Memory_AppendFreePoolNode(void);
// Original: arm9/ov001 @ 0x0215A6BC; symbol: func_ov001_0215a6bc; size: 0x20.
extern "C" void func_ov001_0215a6bc(void *unused, unsigned int value) {
    unsigned int *p = Memory_AppendFreePoolNode();
    if (p) { p[0] = 0x18; *(unsigned int *)((unsigned char *)p + 0x10) = value; }
}
