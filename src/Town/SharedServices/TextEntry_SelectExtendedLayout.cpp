#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EF34; symbol: func_ov003_0215ef34; size: 0x18.
extern "C" int TextEntry_SelectExtendedLayout(unsigned char *p) {
    p[0x1e] = 8;
    p[0x20] = 0;
    return 0xb;
}
