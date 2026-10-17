#include <globaldefs.h>
ARM
extern "C" int func_ov031_02210ef8(void);
extern "C" int func_ov031_0221042c(void *);
// Original: arm9/ov031 @ 0x0221032C; symbol: func_ov031_0221032c; size: 0x2C.
extern "C" int GlobalState7_CallObjectOrReturnMinus56(void *object) {
    int result = -0x38;
    if (func_ov031_02210ef8() != 0)
        result = func_ov031_0221042c(object);
    return result;
}
