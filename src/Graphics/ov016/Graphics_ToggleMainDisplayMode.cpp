#include <globaldefs.h>
ARM
extern "C" void Graphics_SetMainDisplayModeAndSelection(unsigned short, unsigned, int);
extern "C" volatile unsigned char data_ov016_0219d0c0[];
// Original: arm9/ov016 @ 0x0218BE7C; symbol: func_ov016_0218be7c; size: 0x48.
extern "C" void Graphics_ToggleMainDisplayMode(void) {
    if (*(volatile unsigned*)(data_ov016_0219d0c0 + 0x18) == 0)
        Graphics_SetMainDisplayModeAndSelection(6, 0, 0);
    else
        Graphics_SetMainDisplayModeAndSelection(2, 0, 0);
    *(volatile unsigned*)(data_ov016_0219d0c0 + 0x18) = *(volatile unsigned*)(data_ov016_0219d0c0 + 0x18) ^ 1;
}
