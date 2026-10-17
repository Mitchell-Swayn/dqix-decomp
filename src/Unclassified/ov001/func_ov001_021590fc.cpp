#include <globaldefs.h>
ARM
extern "C" unsigned int *Queue_AppendNodeFromFreeList(void);
// Original: arm9/ov001 @ 0x021590FC; symbol: func_ov001_021590fc; size: 0x20.
extern "C" void func_ov001_021590fc(void *unused, unsigned int value) {
    unsigned int *p = Queue_AppendNodeFromFreeList();
    if (p) { p[0] = 0xb; *(unsigned int *)((unsigned char *)p + 0x1c) = value; }
}
