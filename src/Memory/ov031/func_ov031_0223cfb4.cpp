#include <globaldefs.h>
ARM
extern "C" unsigned int _Z25DisableSpecificInterruptsj(unsigned int);
extern "C" void _Z24EnableSpecificInterruptsj(unsigned int);
extern "C" void _ZN13HPXEAllocator4FreeEPv(void *, void *);
extern "C" unsigned char data_ov031_02290d3c[];
// Original: arm9/ov031 @ 0x0223CFB4; symbol: func_ov031_0223cfb4; size: 0x3C.
extern "C" void func_ov031_0223cfb4(void *ptr) {
    unsigned int state = _Z25DisableSpecificInterruptsj(1);
    if (ptr == 0) return;
    _ZN13HPXEAllocator4FreeEPv(*(void **)data_ov031_02290d3c, ptr);
    _Z24EnableSpecificInterruptsj(state);
}
