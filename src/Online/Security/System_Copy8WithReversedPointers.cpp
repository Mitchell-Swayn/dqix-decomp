#include <globaldefs.h>
THUMB
extern "C" void MI_CpuCopy8(const void *src, void *dst, unsigned int length);
// Original: arm9/ov031 @ 0x0221E51C; symbol: func_ov031_0221e51c; size: 0x10.
extern "C" void System_Copy8WithReversedPointers(void *destination, const void *source, unsigned int length) {
    MI_CpuCopy8(source, destination, length);
}
