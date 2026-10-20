#include <globaldefs.h>
ARM
extern "C" void ColorEffect_ConfigureBrightnessAdjust(int control, unsigned int pixelSource, int adjust);
extern "C" void Graphics_ConfigureFixedGeometryState(void*,int,int);
// Original: arm9/ov023 @ 0x021DAC40; symbol: func_ov023_021dac40; size: 0x94.
extern "C" void Graphics_AdvanceTimedFade(char *self, int elapsed) {
    if (!(*(unsigned*)(self + 0xd9c) & 0x10000)) return;
    *(short*)(self + 0xd98) -= elapsed;
    if (*(short*)(self + 0xd98) < 0) *(short*)(self + 0xd98) = 0;
    if (*(unsigned*)(self + 0xd9c) & 0x800000) {
        int value = (*(short*)(self + 0xd98) * 31) / 90;
        Graphics_ConfigureFixedGeometryState(self, 0, 31 - value);
    } else {
        int value = -((90 - *(short*)(self + 0xd98)) * 16) / 90;
        ColorEffect_ConfigureBrightnessAdjust(0x04000050, 0x16, value);
    }
}
