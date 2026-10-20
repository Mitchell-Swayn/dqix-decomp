#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02197324; symbol: func_ov017_02197324; size: 0x38.
extern "C" void ClearMatchingHalfwordEntry(void *self, unsigned short value) {
    unsigned short *entry = (unsigned short *)((unsigned char *)self + 0x44b8);
    for (int i = 0; i < 4; ++i, ++entry) {
        unsigned short current = *entry;
        if (current == value) {
            *entry = 0;
            return;
        }
    }
}
