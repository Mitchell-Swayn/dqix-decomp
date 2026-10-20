#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D4DrawEb(void *object, bool enabled);
// Original: arm9/ov023 @ 0x021FCFE8; symbol: func_ov023_021fcfe8; size: 0x20.
extern "C" void Graphics_DrawEmbeddedObjectUnlessFlagged(void *owner) {
    if (*((unsigned char *)owner + 0x0c) & 8)
        return;
    _ZN8Object3D4DrawEb((char *)owner + 0x20, true);
}
