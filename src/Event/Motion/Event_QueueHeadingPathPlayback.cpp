#include <globaldefs.h>
ARM
extern "C" unsigned int *Pool_AppendFreeNode(void);
// Original: arm9/ov001 @ 0x0215A42C; symbol: func_ov001_0215a42c; size: 0x20.
extern "C" void Event_QueueHeadingPathPlayback(void *unused, unsigned int value) {
    unsigned int *p = Pool_AppendFreeNode();
    if (p) { p[0] = 6; *(unsigned int *)((unsigned char *)p + 0x10) = value; }
}
