#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d82e0[];
extern "C" bool Object_TestBoundedBitAtOffset55D(unsigned char *p, int i);
// Original: arm9/ov017 @ 0x0218B628; symbol: func_ov017_0218b628; size: 0x3C.
extern "C" int Object_TestNestedBitAtOffset55D(int index) {
    unsigned char *base = *(unsigned char **)(data_ov017_021d82e0 + 4);
    if (base == 0) {
        return 0;
    }
    unsigned char *field = *(unsigned char **)(base + 0x36D0);
    if (field == 0) {
        return 0;
    }
    return Object_TestBoundedBitAtOffset55D(field, index);
}
