#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0219A644; symbol: func_ov017_0219a644; size: 0x30.
extern "C" void ClearFourRecordHalfwordsAt3D00(void *base) {
    unsigned int zero = 0;
    unsigned char i = 0;
    while (i < 4) {
        *(unsigned short *)((unsigned char *)base + 0x3d00 + (unsigned int)i * 0xe0 + 0xb6) = zero;
        ++i;
    }
}
