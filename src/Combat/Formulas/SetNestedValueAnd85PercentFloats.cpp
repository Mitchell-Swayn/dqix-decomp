#include <globaldefs.h>
ARM
extern "C" int GameObject_GetCurrentVocationLevel(void*);
extern "C" int _fflt(int);
extern "C" double _dflt(int);
extern "C" double _dmul(double, double);
extern "C" int _d2f(void);
// Original: arm9/ov024 @ 0x021F729C; symbol: SetNestedValueAnd85PercentFloats; size: 0x5C.
// Doubles the nested value with minimum 0x23, stores its float form at +0x1C and the 0.85-scaled float at +0x20.
extern "C" int SetNestedValueAnd85PercentFloats(void* p) {
    int value = GameObject_GetCurrentVocationLevel(*(void**)p) * 2;
    if (value < 0x23) value = 0x23;
    *(unsigned int*)((char*)p + 0x1c) = (unsigned int)_fflt(value);
    (void)_dmul(0.85, _dflt(value));
    *(unsigned int*)((char*)p + 0x20) = (unsigned int)_d2f();
    return 1;
}
