#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void *src, void *dst, unsigned length);
// Original: arm9/ov031 @ 0x0220AB94; symbol: func_ov031_0220ab94; size: 0x18.
extern "C" void Memory_CopyBytesThroughSdkByteCopy(void *dst, const void *src, unsigned length) {
    MI_CpuCopy8(src, dst, length);
}
