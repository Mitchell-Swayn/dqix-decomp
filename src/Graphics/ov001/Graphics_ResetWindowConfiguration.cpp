#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_02165880[];
extern "C" unsigned char data_ov001_021658b8[];
extern "C" void func_ov001_021588bc(void*, void*, unsigned);
// Original: arm9/ov001 @ 0x0215A954; symbol: func_ov001_0215a954; size: 0x60.
extern "C" void Graphics_ResetWindowConfiguration(void) {
    volatile unsigned short* display = (volatile unsigned short*)0x04000060;
    unsigned short control = *display;
    *display = (control & ~0x3000) | 4;
    *(volatile unsigned short*)0x04000340 = 0;
    func_ov001_021588bc(*(void**)(data_ov001_02165880 + 0x24), *(void**)(data_ov001_02165880 + 8), 8);
    *(unsigned*)(data_ov001_021658b8 + 0xEC) = 0;
    if (*(unsigned*)(data_ov001_021658b8 + 0xE4) != 0)
        *(unsigned*)(data_ov001_021658b8 + 0xE4) = 0;
}
