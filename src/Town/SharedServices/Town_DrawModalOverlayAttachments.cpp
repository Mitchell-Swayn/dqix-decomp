#include <globaldefs.h>
ARM
extern "C" void World_DrawStageObjectAttachments(void *);
// Original: arm9/ov003 @ 0x0217EEDC; symbol: func_ov003_0217eedc; size: 0x18.
extern "C" void Town_DrawModalOverlayAttachments(void *p) {
    void *state = *(void **)((unsigned char *)p + 0x1c);
    if (state) World_DrawStageObjectAttachments(state);
}
