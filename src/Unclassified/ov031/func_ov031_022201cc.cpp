#include <globaldefs.h>
THUMB
extern "C" void func_ov031_02220190(int a, int b, int c);
// Original: arm9/ov031 @ 0x022201CC; symbol: func_ov031_022201cc; size: 0xC.
extern "C" void func_ov031_022201cc(int a, int ignored, int b, int c) {
    func_ov031_02220190(a, b, c);
}
