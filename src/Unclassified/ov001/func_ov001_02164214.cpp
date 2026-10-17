#include <globaldefs.h>
ARM
extern "C" int func_ov001_02164194(void *, unsigned, unsigned, unsigned);
// Original: arm9/ov001 @ 0x02164214; symbol: func_ov001_02164214; size: 0x34.
extern "C" int func_ov001_02164214(void *base, int index, unsigned type, unsigned value, unsigned valid) {
    if (index < 0 || index >= 0x20) return 0;
    return func_ov001_02164194((char *)base + index * 0x10, type, value, valid);
}
