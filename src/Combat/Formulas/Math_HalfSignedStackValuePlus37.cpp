#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021D9D6C; symbol: func_ov024_021d9d6c; size: 0x14.
extern "C" int Math_HalfSignedStackValuePlus37(int a, int b, int c, int d, int e, int value) {
    return ((int)(value + ((unsigned int)value >> 31)) >> 1) + 0x25;
}
