#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
// Original: arm9/ov025 @ 0x021E86F0; symbol: func_ov025_021e86f0; size: 0x18.
extern "C" void Combat_EnableActionResourceFlag448A(void) {
    volatile unsigned char *p = (volatile unsigned char *)GameResources_GetInstance() + 0x4000;
    p[0x48a] = 1;
}
