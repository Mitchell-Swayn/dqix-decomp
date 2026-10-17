#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E616C; symbol: func_ov023_021e616c; size: 0x28.
extern "C" void InitializeTenEntryHalfwordSentinels(void *base) {
    for (int i = 0; i < 10; ++i)
        *(short *)((char *)base + i * 0xac + 2) = -1;
}
