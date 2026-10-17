#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e5c4;
// Original: arm9/ov031 @ 0x022134F0; symbol: func_ov031_022134f0; size: 0x14.
extern "C" unsigned int func_ov031_022134f0(void) {
    unsigned char *p = (unsigned char *)&data_ov031_0224e5c4;
    p = *(unsigned char **)(p + 0xc);
    return *(unsigned int *)(p + 0xc);
}
