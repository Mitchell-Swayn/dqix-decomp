#include <globaldefs.h>
ARM
extern "C" void Graphics_CleanConfiguredDestinationCache(void *, int);
// Original: arm9/ov023 @ 0x021F7884; symbol: func_ov023_021f7884; size: 0x20.
extern "C" void Graphics_CleanConfiguredDestinationCacheIfFlagClear(void *p) {
    if ((*(unsigned char *)((char *)p + 0xc) & 1) == 0)
        Graphics_CleanConfiguredDestinationCache((char *)p + 0x28, 0);
}
