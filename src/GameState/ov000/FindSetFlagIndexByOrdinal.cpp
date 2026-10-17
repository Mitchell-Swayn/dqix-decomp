#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0218158C; symbol: func_ov000_0218158c; size: 0x3C.
extern "C" unsigned FindSetFlagIndexByOrdinal(void *self, unsigned ordinal) {
    unsigned flags = *(unsigned *)((unsigned char *)self + 0x68);
    int found = 0;
    for (int bit = 0; bit < 12; ++bit) {
        if (flags & (1u << bit)) {
            if (found == ordinal) return bit;
            ++found;
        }
    }
    return 0;
}
