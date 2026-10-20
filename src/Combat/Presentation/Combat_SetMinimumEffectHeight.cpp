#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED110; symbol: func_ov025_021ed110; size: 0xC.
extern "C" void Combat_SetMinimumEffectHeight(void *arg0, unsigned short arg1) {
    *(unsigned short *)((char *)arg0 + 0x304) = arg1;
}
