#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void *, void *, unsigned int);
// Original: arm9/ov031 @ 0x0223FB74; symbol: func_ov031_0223fb74; size: 0x18.
extern "C" void Memory_Copy8(void *dest, const void *src, unsigned int size) {
    MI_CpuCopy8(src, dest, size);
}
