#include <globaldefs.h>
ARM

// Original: arm9/ov031 @ 0x02216710; symbol: func_ov031_02216710; size: 0x34.
extern "C" int Util_AreFirstTenBytesPrintable(const char *text) {
    int i = 0;
    do {
        unsigned char ch = (unsigned char)text[i];
        if (ch < 0x20 || ch > 0x7e) {
            return 0;
        }
    } while (++i < 10);
    return 1;
}
