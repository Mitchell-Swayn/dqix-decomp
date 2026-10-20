#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
// Original: arm9/ov025 @ 0x021E861C; symbol: func_ov025_021e861c; size: 0x1C.
extern "C" int Combat_DisableActionSelectorGate(void) {
    volatile unsigned char *base = (volatile unsigned char *)GameResources_GetInstance();
    *(base + 0x4488) = 0;
    return 1;
}
