#include <globaldefs.h>
ARM
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned int);
extern "C" void LoadToMainOAM(const void *, unsigned int, unsigned int);
extern "C" void LoadToSubOAM(const void *, unsigned int, unsigned int);
extern "C" unsigned char * volatile data_ov031_02290d60;

// Original: arm9/ov031 @ 0x0223D9C4; symbol: func_ov031_0223d9c4; size: 0x48.
extern "C" void Graphics_FlushAndLoadOAM(void) {
    _Z25CleanInvalidateCacheRangePKvj(data_ov031_02290d60, 0x800);
    LoadToMainOAM(data_ov031_02290d60, 0, 0x400);
    LoadToSubOAM(data_ov031_02290d60 + 0x400, 0, 0x400);
}
