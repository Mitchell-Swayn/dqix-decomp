#include <globaldefs.h>
THUMB
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" unsigned long long _ll_udiv(unsigned long long, unsigned long long);
// Original: arm9/ov031 @ 0x02222870; symbol: func_ov031_02222870; size: 0x1C.
extern "C" unsigned long long Time_GetScaledCurrentTimestamp(void) {
    return _ll_udiv(_Z19GetCurrentTimestampv() << 6, 0x82ea);
}
