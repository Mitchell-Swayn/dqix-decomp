#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov001 @ 0x0215E900; symbol: func_ov001_0215e900; size: 0x20.
extern "C" int Script_SetCurrentBytes195DAnd19C0(void) {
    unsigned int base = ReadWordFieldAtOffset1C();
    base += 0x1000;
    *(unsigned char *)(base + 0x9c0) = 1;
    *(unsigned char *)(base + 0x95d) = 0x1e;
    return 1;
}
