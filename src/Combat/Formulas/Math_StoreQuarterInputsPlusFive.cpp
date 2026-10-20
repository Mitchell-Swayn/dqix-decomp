#include <globaldefs.h>
ARM
extern "C" void *GameObject_GetCurrentVocationLevel(void *);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" unsigned int _fadd(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F7244; symbol: Math_StoreQuarterInputsPlusFive; size: 0x58.
// Runs the nested-field reader, computes each input float divided by four plus five, stores them at +0x1C and +0x20, and returns true.
extern "C" int Math_StoreQuarterInputsPlusFive(void *obj) {
    GameObject_GetCurrentVocationLevel(*(void **)obj);
    unsigned int value = _fdiv(*(unsigned int *)((char *)obj + 0x14), 0x40800000);
    *(unsigned int *)((char *)obj + 0x1c) = _fadd(0x40a00000, value);
    value = _fdiv(*(unsigned int *)((char *)obj + 0x18), 0x40800000);
    *(unsigned int *)((char *)obj + 0x20) = _fadd(0x40a00000, value);
    return 1;
}
