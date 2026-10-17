#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02250bfc;
// Original: arm9/ov031 @ 0x02223FA0; symbol: func_ov031_02223fa0; size: 0x14.
extern "C" unsigned int func_ov031_02223fa0(void) {
    unsigned char *p = *(unsigned char **)&data_ov031_02250bfc;
    return p[0x11c];
}
