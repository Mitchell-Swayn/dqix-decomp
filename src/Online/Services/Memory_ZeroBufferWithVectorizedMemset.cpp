#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
// Original: arm9/ov031 @ 0x022415B4; symbol: func_ov031_022415b4; size: 0x14.
extern "C" void Memory_ZeroBufferWithVectorizedMemset(void *p, unsigned int size) {
    VectorizedMemset(p, 0, size);
}
