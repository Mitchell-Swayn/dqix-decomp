#include <globaldefs.h>
ARM
extern unsigned char data_ov031_02290ce8[];
extern "C" void MIi_CpuCopy16(const void *, volatile void *, int);
extern "C" void func_ov031_0223e2c0(int, int);
// Original: arm9/ov031 @ 0x0223508C; symbol: func_ov031_0223508c; size: 0x30.
extern "C" void Graphics_CopyPaletteToBackgroundPaletteAndApplyMode(int mode) {
    MIi_CpuCopy16(*(void **)(data_ov031_02290ce8 + 4), (volatile void *)0x05000000, 0x200);
    func_ov031_0223e2c0(1, mode);
}
