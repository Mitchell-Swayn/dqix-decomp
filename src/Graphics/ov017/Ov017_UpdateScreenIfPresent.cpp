#include <globaldefs.h>
ARM
extern "C" void func_ov012_02185a24(unsigned char *screen);
// Original: arm9/ov017 @ 0x021C19F8; symbol: func_ov017_021c19f8; size: 0x18.
extern "C" void Ov017_UpdateScreenIfPresent(void *owner) {
    unsigned char *screen = *(unsigned char **)((char *)owner + 0x20);
    if (screen)
        func_ov012_02185a24(screen);
}
