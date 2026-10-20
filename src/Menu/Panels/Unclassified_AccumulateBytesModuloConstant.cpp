#include <globaldefs.h>
ARM

extern "C" unsigned long long _ull_mod(unsigned long long, unsigned long long);

// Original: arm9/ov023 @ 0x021F6324; symbol: func_ov023_021f6324; size: 0x54.
extern "C" unsigned long long Unclassified_AccumulateBytesModuloConstant(int count, const unsigned char *bytes) {
    unsigned long long value = 0;
    while (count-- > 0) {
        value = _ull_mod((value << 8) + *bytes++, 0xc2a030d4ULL);
    }
    return value;
}
