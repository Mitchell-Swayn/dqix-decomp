#include <globaldefs.h>
ARM

extern "C" int Network_SendIpcCommandAndInvalidateResponse(const void *, unsigned, const void *);
extern "C" int RuntimeMemory_CompareByteRanges(const void *, const void *, unsigned);

// Original: arm9/ov031 @ 0x0221B7FC; symbol: func_ov031_0221b7fc; size: 0x4C.
extern "C" int Network_ValidateAndCompareByteRange(const void *expected, const void *candidate, unsigned length, const void *other) {
    if (Network_SendIpcCommandAndInvalidateResponse(candidate, length, other) == 0) {
        return 0;
    }
    return RuntimeMemory_CompareByteRanges(expected, other, length) == 0;
}
