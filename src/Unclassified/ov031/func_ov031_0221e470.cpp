#include <globaldefs.h>
THUMB
extern "C" unsigned int data_ov031_0224f4cc;
// Original: arm9/ov031 @ 0x0221E470; symbol: func_ov031_0221e470; size: 0x10.
extern "C" int func_ov031_0221e470(void *unused, unsigned int arg) {
    return ((int (*)(unsigned int))data_ov031_0224f4cc)(arg);
}
