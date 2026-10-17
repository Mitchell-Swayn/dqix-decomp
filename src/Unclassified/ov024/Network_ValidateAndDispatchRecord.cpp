#include <globaldefs.h>
ARM
extern "C" int func_ov000_0215e9fc(unsigned value, unsigned extra, unsigned a, unsigned b);
extern "C" void func_ov024_021ed8c0(void *arg0, unsigned arg1, unsigned arg2, unsigned *result, unsigned extra);
// Original: arm9/ov024 @ 0x021F1844; symbol: func_ov024_021f1844; size: 0x5C.
extern "C" int Network_ValidateAndDispatchRecord(const unsigned *value, unsigned arg1, unsigned arg2, unsigned *result, unsigned extra) {
    int validation = func_ov000_0215e9fc(*value, extra, 4, 1);
    *result = validation;
    if (validation <= 0) return 0;
    func_ov024_021ed8c0((void *)value, arg1, arg2, result, extra);
    return 1;
}
