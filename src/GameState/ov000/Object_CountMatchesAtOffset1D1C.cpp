#include <globaldefs.h>
ARM
extern "C" unsigned data_ov000_02184288[];
// Original: arm9/ov000 @ 0x02175348; symbol: func_ov000_02175348; size: 0x44.
extern "C" int Object_CountMatchesAtOffset1D1C(unsigned char* base, unsigned value) {
    int length = data_ov000_02184288[1];
    int count = 0;
    int i = 0;
    for (; i < length; ++i) {
        unsigned entry = *(unsigned*)(base + 0x1d1c + i * 4);
        if (value == entry) ++count;
    }
    return count;
}
