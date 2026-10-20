#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021570B4; symbol: func_ov006_021570b4; size: 0x48.
extern "C" int KrakPot_HasPendingItemPreviewLoads(unsigned char *state) {
    unsigned char *p = state + 0x894;
    int result = 0;
    for (unsigned char i = 0; i < 4; ++i) {
        result = (result | p[0x7a]) ? 1 : 0;
        p += 0x7c;
    }
    return result;
}
