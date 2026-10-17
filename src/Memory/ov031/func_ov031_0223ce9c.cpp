#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void *_ZN13HPXEAllocator16CreateAtLocationEPvjt(void *, unsigned, unsigned short);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void *data_ov031_02290d3c;
// Original: arm9/ov031 @ 0x0223CE9C; symbol: func_ov031_0223ce9c; size: 0x40.
extern "C" void func_ov031_0223ce9c(void *location) {
    VectorizedMemset(location, 0, 0x40000);
    void *allocator = _ZN13HPXEAllocator16CreateAtLocationEPvjt(location, 0x40000, 0);
    data_ov031_02290d3c = allocator;
    if (allocator == 0) DisableInterruptsAndHaltForever();
}
