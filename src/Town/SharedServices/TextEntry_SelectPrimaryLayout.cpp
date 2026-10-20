#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EE88; symbol: func_ov003_0215ee88; size: 0x18.
extern "C" int TextEntry_SelectPrimaryLayout(void *record) {
    *((unsigned char *)record + 0x1e) = 1;
    *((unsigned char *)record + 0x20) = 0;
    return 6;
}
