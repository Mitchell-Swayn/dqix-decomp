#include <globaldefs.h>
ARM
extern "C" int Math_GetSignificantHalfwordCount(const unsigned short *p, int count);
// Original: arm9/ov031 @ 0x0220BB4C; symbol: Util_RejectHighBitLastHalfwordOrCheckTrimmedLength; size: 0x30.
// Returns -1 when the final halfword has bit 15 set; otherwise returns whether trimming trailing zero halfwords leaves any data.
extern "C" int Util_RejectHighBitLastHalfwordOrCheckTrimmedLength(const unsigned short *p, int count) {
    if (p[count - 1] & 0x8000) return -1;
    return Math_GetSignificantHalfwordCount(p, count) != 0;
}
