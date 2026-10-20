#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x0215E514; symbol: func_ov001_0215e514; size: 0x28.
extern "C" int Script_EnableUnknownMessageStyleFlag40(void) {
    unsigned char *object = (unsigned char *)TextContext_GetSharedInstance();
    if (!object) return 0;
    object[0x195b] |= 0x40;
    return 1;
}
