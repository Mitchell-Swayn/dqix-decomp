#include <globaldefs.h>
ARM
extern "C" void ClearSelectedBufferUsingFormatSizeTable(unsigned char *, void *);
// Original: arm9/ov023 @ 0x021F7864; symbol: func_ov023_021f7864; size: 0x20.
extern "C" void func_ov023_021f7864(unsigned char *p) {
    if ((p[0xc] & 1) == 0) ClearSelectedBufferUsingFormatSizeTable(p + 0x28, 0);
}
