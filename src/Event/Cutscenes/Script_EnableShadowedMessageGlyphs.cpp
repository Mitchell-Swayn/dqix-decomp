#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void *);
// Original: arm9/ov001 @ 0x0215E53C; symbol: Resource_SetBit1AtResolvedStateOffset195B; size: 0x28.
// Reads the pointer at input offset 0x1c; if nonzero, sets bit 1 at pointer offset 0x195b and returns one.
extern "C" int Script_EnableShadowedMessageGlyphs(void *p) {
    unsigned int base = TextContext_GetSharedInstance(p);
    if (!base)
        return 0;
    unsigned char *flag = (unsigned char *)(base + 0x195b);
    *flag |= 2;
    return 1;
}
