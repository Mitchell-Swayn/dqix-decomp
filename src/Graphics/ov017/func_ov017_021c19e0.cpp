#include <globaldefs.h>
ARM
extern "C" void func_ov012_02185ab8(unsigned char *);
// Original: arm9/ov017 @ 0x021C19E0; symbol: func_ov017_021c19e0; size: 0x18.
extern "C" void func_ov017_021c19e0(void *p) {
    unsigned char *screen = *(unsigned char **)((unsigned char *)p + 0x20);
    if (screen) func_ov012_02185ab8(screen);
}
