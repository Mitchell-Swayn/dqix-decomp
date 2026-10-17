#include <globaldefs.h>
ARM
extern "C" unsigned *data_ov017_021d83ac;
// Original: arm9/ov017 @ 0x021A5A48; symbol: func_ov017_021a5a48; size: 0x20.
extern "C" unsigned func_ov017_021a5a48(void) {
    unsigned char result = 0xff;
    if (data_ov017_021d83ac)
        result = *((unsigned char *)data_ov017_021d83ac + 0x1c79);
    return result;
}
