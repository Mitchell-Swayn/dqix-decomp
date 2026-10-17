#include <globaldefs.h>
ARM
extern "C" void func_ov000_0218177c(int, int, int, int, int);
// Original: arm9/ov000 @ 0x02181A5C; symbol: func_ov000_02181a5c; size: 0x18.
extern "C" void Util_CallTargetWithFlagsOne(int a0, int a1, int a2) {
    func_ov000_0218177c(a0, a1, 1, 1, a2);
}
