#include <globaldefs.h>
THUMB
extern "C" unsigned int data_ov031_0224f4c0[];
// Original: arm9/ov031 @ 0x0221ECB4; symbol: func_ov031_0221ecb4; size: 0x14.
extern "C" int InvokeOptionalCallbackAtGlobalOffset4(unsigned int arg) {
    unsigned int callback = data_ov031_0224f4c0[1];
    if (callback)
        ((void (*)(unsigned int))callback)(arg);
    return 0;
}
