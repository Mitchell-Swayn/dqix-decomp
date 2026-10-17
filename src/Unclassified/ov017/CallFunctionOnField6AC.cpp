#include <globaldefs.h>
ARM
extern "C" void func_ov000_02160b54(void *);
// Original: arm9/ov017 @ 0x021B8408; symbol: func_ov017_021b8408; size: 0x18.
extern "C" void CallFunctionOnField6AC(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x6ac);
    if (value != 0)
        func_ov000_02160b54(value);
}
