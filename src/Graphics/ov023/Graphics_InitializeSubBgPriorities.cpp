#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C();
// Original: arm9/ov023 @ 0x021D8EA0; symbol: func_ov023_021d8ea0; size: 0x8C.
extern "C" void Graphics_InitializeSubBgPriorities(char *self) {
    unsigned char state = *(unsigned char*)(self + 0x11b);
    if (state == 0xff) return;
    if (state != 0) return;
    *(unsigned*)(self + 4) = *(unsigned*)(ReadWordFieldAtOffset1C() + 0x5c);
    volatile unsigned short *bg = (volatile unsigned short*)0x04001008;
    bg[0] = (bg[0] & ~3) | 1;
    bg[1] = (bg[1] & ~3) | 2;
    bg[2] = bg[2] & ~3;
    bg[3] = (bg[3] & ~3) | 3;
    volatile unsigned *display = (volatile unsigned*)0x04001000;
    *display = (*display & ~0x1f00) | 0x700;
    *(unsigned char*)(self + 0x11b) = 0xff;
}
