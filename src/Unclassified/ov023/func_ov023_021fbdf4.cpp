#include <globaldefs.h>
ARM
extern "C" void func_ov023_021ddf5c(void *, unsigned int);
// Original: arm9/ov023 @ 0x021FBDF4; symbol: func_ov023_021fbdf4; size: 0x14.
extern "C" void func_ov023_021fbdf4(void *p, unsigned int value) {
    *((unsigned char *)p + 0x79a) = value;
    func_ov023_021ddf5c((unsigned char *)p + 0x20, value);
}
