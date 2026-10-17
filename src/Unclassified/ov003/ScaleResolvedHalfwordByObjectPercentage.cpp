#include <globaldefs.h>
ARM
extern "C" unsigned _u32_div_f(unsigned,unsigned);
extern "C" unsigned Object_ResolveEncodedHalfwordThroughCallbackTable(unsigned short* p);
// Original: arm9/ov003 @ 0x02175898; symbol: func_ov003_02175898; size: 0x34.
// Scales a resolved encoded halfword by the unsigned percentage at object offset 0x86C.
extern "C" unsigned ScaleResolvedHalfwordByObjectPercentage(char *p, unsigned short *encoded) {
    if (!encoded) return 0;
    unsigned value = Object_ResolveEncodedHalfwordThroughCallbackTable(encoded);
    return _u32_div_f(*(unsigned short *)(p + 0x86c) * value, 100);
}
