#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x0215E564; symbol: func_ov001_0215e564; size: 0x24.
extern "C" int Script_DisableUnknownAlternateMessageMode(void) {
    unsigned int object = TextContext_GetSharedInstance();
    if (!object)
        return 0;
    *(unsigned char *)(object + 0x19b2) = 0;
    return 1;
}
