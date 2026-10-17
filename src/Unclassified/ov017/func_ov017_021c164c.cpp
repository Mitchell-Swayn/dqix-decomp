#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov017_021d8478[];
extern "C" void Graphics_UpdatePartyEffectAndDraw(void *);
// Original: arm9/ov017 @ 0x021C164C; symbol: func_ov017_021c164c; size: 0x20.
extern "C" void func_ov017_021c164c(void) {
    void *p = (void *)data_ov017_021d8478[0];
    if (p) Graphics_UpdatePartyEffectAndDraw(p);
}
