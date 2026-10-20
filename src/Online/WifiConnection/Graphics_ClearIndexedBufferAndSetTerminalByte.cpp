#include <globaldefs.h>
ARM
extern "C" void MIi_CpuClear16(int value, void *dst, unsigned len);
// Original: arm9/ov031 @ 0x0221BE38; symbol: func_ov031_0221be38; size: 0x2C.
extern "C" void Graphics_ClearIndexedBufferAndSetTerminalByte(void *base, unsigned int index) {
    MIi_CpuClear16(0, (char *)base + index * 0x100, 0x100);
    *((unsigned char *)base + index * 0x100 + 0xe7) = 0xff;
}
