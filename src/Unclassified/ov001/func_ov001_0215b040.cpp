#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
// Original: arm9/ov001 @ 0x0215B040; symbol: func_ov001_0215b040; size: 0x18.
extern "C" void func_ov001_0215b040(void) {
    unsigned char *base = (unsigned char *)_ZN9GameState11GetInstanceEv() + 0x5000;
    *(volatile unsigned char *)(base + 0xcac) = 1;
}
