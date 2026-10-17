#include <globaldefs.h>
ARM
extern "C" signed char* data_ov031_02290d10;
extern "C" void ColorEffect_ChangeBrightness(int control, int newBrightness);
extern "C" void OV031_WriteWordField08(void* self, unsigned value);
extern "C" void func_ov031_022385e4(void);
// Original: arm9/ov031 @ 0x02238588; symbol: func_ov031_02238588; size: 0x5C.
extern "C" void Graphics_AdvanceBrightnessFade(void* object) {
    data_ov031_02290d10[0x1a]++;
    ColorEffect_ChangeBrightness(0x04000050, data_ov031_02290d10[0x1a]);
    if (data_ov031_02290d10[0x1a] >= 0)
        OV031_WriteWordField08(object, (unsigned)func_ov031_022385e4);
}
