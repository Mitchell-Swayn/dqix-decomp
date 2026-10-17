#include <globaldefs.h>
ARM
extern void *data_ov031_02290d10;
extern "C" void ColorEffect_ChangeBrightness(unsigned int control, int brightness);
extern "C" void OV031_WriteWordField08(void *, unsigned);
extern "C" void func_ov031_02237f2c(void);
// Original: arm9/ov031 @ 0x02237ECC; symbol: func_ov031_02237ecc; size: 0x60.
extern "C" void GameState_DecrementGlobalBrightnessAndNotifyAtMinusTwelve(void *self) {
    (*(signed char *)((unsigned char *)data_ov031_02290d10 + 0x1A))--;
    ColorEffect_ChangeBrightness(0x04000050, *(signed char *)((unsigned char *)data_ov031_02290d10 + 0x1A));
    if (*(signed char *)((unsigned char *)data_ov031_02290d10 + 0x1A) > -12) return;
    OV031_WriteWordField08(self, (unsigned)func_ov031_02237f2c);
}
