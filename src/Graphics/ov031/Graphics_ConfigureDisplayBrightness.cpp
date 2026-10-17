#include <globaldefs.h>
ARM

extern "C" unsigned int Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(int, unsigned int, int);
extern "C" unsigned int data_ov031_02290d34[];

// Original: arm9/ov031 @ 0x0223BFF8; symbol: func_ov031_0223bff8; size: 0x48.
extern "C" void Graphics_ConfigureDisplayBrightness(void) {
    data_ov031_02290d34[0] = Memory_AllocateZeroedBlock(0x18, 4);
    ColorEffect_ConfigureBrightnessAdjust(0x04000050, 0x3F, 0x10);
    ColorEffect_ConfigureBrightnessAdjust(0x04001050, 0x3F, 0x10);
}
