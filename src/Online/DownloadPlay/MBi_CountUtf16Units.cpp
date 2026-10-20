#include <globaldefs.h>
ARM
// Original: arm9/ov027 @ 0x021DAD84; symbol: func_ov027_021dad84; size: 0x28.
extern "C" unsigned int MBi_CountUtf16Units(const unsigned short *text) {
    unsigned short value = *text++;
    unsigned int count = 0;
    if (value != 0) {
        do {
            value = *text++;
            ++count;
        } while (value != 0);
    }
    return count;
}
