#include <globaldefs.h>
ARM
extern "C" int func_ov031_022036a8(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x0220376C; symbol: func_ov031_0220376c; size: 0x3C.
extern "C" void System_ValidateAndApplyContextPair(unsigned int first, unsigned int second, unsigned int left, unsigned int right, unsigned int mode, unsigned int value) {
    int valid = func_ov031_022036a8(first, second, mode, value);
    if (valid != 0 && right != 0) func_ov031_022036a8(left, right, mode, 0);
}
