#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x0215951C; symbol: func_ov006_0215951c; size: 0x48.
extern "C" void func_ov006_0215951c(void *obj) {
    *(unsigned char *)((char *)obj + 0x388) = 0;
    int index = *(short *)((char *)obj + 0x362) - 0x5b;
    int offset = (index << 16) >> 15;
    unsigned short value = *(unsigned short *)(*(unsigned int *)((char *)obj + 0x50) + offset);
    int rounded = ((int)value + 7) / 8;
    *(unsigned char *)((char *)obj + 0x389) = (unsigned char)rounded;
    if ((rounded & 0xff) == 0) *(unsigned char *)((char *)obj + 0x389) = 1;
}
