#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290ca0[];
extern "C" int FastIntDivide(int, int);
// Original: arm9/ov031 @ 0x022305E8; symbol: func_ov031_022305e8; size: 0x24.
extern "C" int Math_AddGlobalValueDividedBy29(int base) {
    int result = FastIntDivide(*(unsigned short *)(data_ov031_02290ca0 + 4), 0x1d);
    result += base;
    return result;
}
