#include <globaldefs.h>
ARM
extern "C" void *OV011_GetObjectIfFieldValueSeven(void *, unsigned);
extern "C" void func_ov004_02158fec(void *);
// Original: arm9/ov004 @ 0x0215CDF0; symbol: func_ov004_0215cdf0; size: 0x48.
extern "C" int Object_DecrementStoredIndexWithFallback(void *owner) {
    unsigned char *object = (unsigned char *)OV011_GetObjectIfFieldValueSeven(owner, 0x5b);
    short first = *(short *)(object + 0x5c);
    short second = *(short *)(object + 0x5e);
    --first;
    if (first < 0) first = second - 1;
    *(short *)(object + 0x5c) = first;
    *(short *)(object + 0x5e) = second;
    func_ov004_02158fec(owner);
    return 0;
}
