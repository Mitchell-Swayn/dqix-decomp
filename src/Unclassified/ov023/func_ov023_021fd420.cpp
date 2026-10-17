#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD420; symbol: func_ov023_021fd420; size: 0x3C.
extern "C" void func_ov023_021fd420(void *object, unsigned short *x, unsigned short *y, unsigned short *right, unsigned short *bottom) {
    *x = *(unsigned short *)((char *)object + 0x22);
    *y = *(unsigned short *)((char *)object + 0x24);
    *right = *x + *(unsigned short *)((char *)object + 0x26);
    *bottom = *y + *(unsigned short *)((char *)object + 0x28);
}
