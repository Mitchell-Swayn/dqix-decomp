#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(void *, const void *, unsigned int);
// Original: arm9/ov031 @ 0x0220ABAC; symbol: func_ov031_0220abac; size: 0x18.
extern "C" void Memory_CopyBytesToFirstArgument(const void *src, void *dst, unsigned int size) { MI_CpuCopy8(dst, src, size); }
