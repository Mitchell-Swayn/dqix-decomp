#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02157570; symbol: func_ov001_02157570; size: 0x1C.
extern "C" void func_ov001_02157570(void *object, unsigned *out) {
    out[0] = *(unsigned *)((char *)object + 0x38c);
    out[1] = *(unsigned *)((char *)object + 0x390);
    out[2] = *(unsigned *)((char *)object + 0x394);
}
