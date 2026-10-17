#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d10;
extern "C" void OV031_WriteWordField08(void *, unsigned);
extern "C" void func_ov031_022384f8(void);
// Original: arm9/ov031 @ 0x022384BC; symbol: func_ov031_022384bc; size: 0x3C.
extern "C" void IncrementGlobalCounterAndNotifyAtEight(void *self) {
    (*(unsigned char *)((unsigned char *)data_ov031_02290d10 + 0x1d))++;
    if (*(unsigned char *)((unsigned char *)data_ov031_02290d10 + 0x1d) >= 8) {
        OV031_WriteWordField08(self, (unsigned)func_ov031_022384f8);
    }
}
