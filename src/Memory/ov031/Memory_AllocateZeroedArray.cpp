#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224f670[];
extern "C" void *memset(void *, int, unsigned int);
typedef void *(*AllocatorFn)(unsigned int);
// Original: arm9/ov031 @ 0x0222288C; symbol: func_ov031_0222288c; size: 0x24.
extern "C" void *Memory_AllocateZeroedArray(unsigned int elementSize, unsigned int count) {
    unsigned int size = elementSize * count;
    AllocatorFn allocate = *(AllocatorFn *)(data_ov031_0224f670 + 4);
    void *result = allocate(size);
    if (result)
        memset(result, 0, size);
    return result;
}
