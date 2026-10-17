#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_021833e8[];
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov000 @ 0x02174DA4; symbol: func_ov000_02174da4; size: 0x1C.
extern "C" void Memory_CopyConstantBlock16(void *, void *dest) {
    memcpy(dest, data_ov000_021833e8, 16);
}
