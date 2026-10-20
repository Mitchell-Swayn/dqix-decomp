#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02171DF0; symbol: func_ov003_02171df0; size: 0x2C.
extern "C" int Util_AreFirstSixBytesZero(const unsigned char *data) {
    for (int i = 0; i < 6; ++i) {
        if (data[i] != 0)
            return 0;
    }
    return 1;
}
