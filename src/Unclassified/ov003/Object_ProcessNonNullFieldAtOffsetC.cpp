#include <globaldefs.h>
ARM
extern "C" void func_ov003_0216d53c(void *);
// Original: arm9/ov003 @ 0x0217F248; symbol: func_ov003_0217f248; size: 0x18.
extern "C" void Object_ProcessNonNullFieldAtOffsetC(void *object) {
    void *value = *(void **)((unsigned char *)object + 0xc);
    if (value)
        func_ov003_0216d53c(value);
}
