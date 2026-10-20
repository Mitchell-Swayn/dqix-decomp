#include <globaldefs.h>
ARM
extern "C" void FieldCommandQueue_DrawActiveCommandOverlay(void *, void *);
// Original: arm9/ov017 @ 0x021A3B30; symbol: func_ov017_021a3b30; size: 0x10.
extern "C" void FieldCommandQueue_DrawFrontOverlay(void **p) {
    FieldCommandQueue_DrawActiveCommandOverlay(p, *p);
}
