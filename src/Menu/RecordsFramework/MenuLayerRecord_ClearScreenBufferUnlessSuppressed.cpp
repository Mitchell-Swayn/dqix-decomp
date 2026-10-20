#include <globaldefs.h>
ARM
extern "C" void Graphics_ClearScreenBuffer(unsigned char *, void *);
// Original: arm9/ov023 @ 0x021F7864; symbol: func_ov023_021f7864; size: 0x20.
extern "C" void MenuLayerRecord_ClearScreenBufferUnlessSuppressed(unsigned char *p) {
    if ((p[0xc] & 1) == 0) Graphics_ClearScreenBuffer(p + 0x28, 0);
}
