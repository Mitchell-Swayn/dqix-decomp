#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02250c40;
extern "C" void func_ov031_02226fe4(void *, unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x0222708C; symbol: func_ov031_0222708c; size: 0x20.
extern "C" void func_ov031_0222708c(unsigned a, unsigned b) {
    func_ov031_02226fe4(&data_ov031_02250c40, a, b, a);
}
