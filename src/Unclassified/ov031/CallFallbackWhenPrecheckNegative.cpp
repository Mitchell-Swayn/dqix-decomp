#include <globaldefs.h>
ARM
extern "C" int func_ov031_02243850(void);
extern "C" void func_ov031_022439d8(void *);
// Original: arm9/ov031 @ 0x022436C0; symbol: func_ov031_022436c0; size: 0x20.
extern "C" void CallFallbackWhenPrecheckNegative(void *argument) {
    if (func_ov031_02243850() < 0)
        func_ov031_022439d8(argument);
}
