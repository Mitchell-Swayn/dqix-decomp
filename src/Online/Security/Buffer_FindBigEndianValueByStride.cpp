#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022089F4; symbol: func_ov031_022089f4; size: 0x4C.
extern "C" int Buffer_FindBigEndianValueByStride(unsigned char* bytes, int count, int stride, unsigned value) {
    int i = 0;
    if (count > 0) {
        do {
            unsigned current = ((unsigned)bytes[0] << 8) + bytes[1];
            if (stride == 3) current = (current << 8) + bytes[2];
            if (current == value) return 1;
            ++i;
            bytes += stride;
        } while (i < count);
    }
    return 0;
}
