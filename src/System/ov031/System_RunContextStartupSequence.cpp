#include <globaldefs.h>
ARM
extern "C" void Math_InitializeDivisionAndInverseSupport(void);
extern "C" void func_ov031_0223e168(int value);
extern "C" void func_ov031_0222b168(void);
extern "C" void func_ov031_0222b1a4(void);
// Original: arm9/ov031 @ 0x0222B36C; symbol: func_ov031_0222b36c; size: 0x1C.
extern "C" void System_RunContextStartupSequence(void) {
    Math_InitializeDivisionAndInverseSupport();
    func_ov031_0223e168(0);
    func_ov031_0222b168();
    func_ov031_0222b1a4();
}
