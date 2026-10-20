#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void *src, void *dst, unsigned int length);
// Original: arm9/ov031 @ 0x022415C8; symbol: func_ov031_022415c8; size: 0x18.
extern "C" void Memory_CopyBytesToDestination(void *dst, const void *src, unsigned int length) {
    MI_CpuCopy8(src, dst, length);
}
