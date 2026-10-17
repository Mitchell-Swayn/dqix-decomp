#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171BC0; symbol: func_ov000_02171bc0; size: 0x44.
extern "C" int Object_CountEntriesWithPositiveHalfword18(unsigned char *base) {
    signed char count = 0;
    for (int i = 0; i < 16; ++i) {
        unsigned char *entry = *(unsigned char **)(base + i * 4 + 0x3F0);
        if (entry != 0 && *(short *)(entry + 0x18) > 0) {
            count = (signed char)(count + 1);
        }
    }
    return count;
}
