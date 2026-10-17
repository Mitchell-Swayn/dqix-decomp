#include <globaldefs.h>
ARM
extern "C" void *func_ov031_0223cf00(unsigned int size);
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
// Original: arm9/ov031 @ 0x0223CF4C; symbol: func_ov031_0223cf4c; size: 0x24.
extern "C" void *Memory_AllocateZeroedBlock(unsigned int size) {
    void *block = func_ov031_0223cf00(size);
    VectorizedMemset(block, 0, size);
    return block;
}
