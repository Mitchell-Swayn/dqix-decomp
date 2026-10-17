#include <globaldefs.h>
ARM
extern "C" void func_ov031_0220520c(int);

// Original: arm9/ov031 @ 0x0220527C; symbol: func_ov031_0220527c; size: 0x10.
extern "C" void func_ov031_0220527c(void *object) {
    func_ov031_0220520c(*(int *)((unsigned char *)object + 0x64));
}
