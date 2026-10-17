#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov023_021fd6ac[];
extern "C" unsigned int data_ov023_021fd6fc[];
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void *, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021E4FD8; symbol: func_ov023_021e4fd8; size: 0x48.
extern "C" void func_ov023_021e4fd8(void *p) {
    for (int i = 0; i < 10; ++i)
        VRAM_SaveStateAndReserveImagePaletteBytes((char *)p + 0x794 + i * 0x70,
            data_ov023_021fd6ac[i], data_ov023_021fd6fc[i]);
}
