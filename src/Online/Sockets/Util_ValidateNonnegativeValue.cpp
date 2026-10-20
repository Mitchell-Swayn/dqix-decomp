#include <globaldefs.h>
ARM
extern "C" int Network_IsSocketHandleInvalid(int);
extern "C" int Util_GlobalNodeListContainsTarget(int);
// Original: arm9/ov031 @ 0x022068CC; symbol: Util_ValidateNonnegativeValue; size: 0x34.
// Accepts a nonnegative value only when the first validator succeeds and the second returns zero.
extern "C" int Util_ValidateNonnegativeValue(int value) {
    if (value < 0) goto fail;
    if (Network_IsSocketHandleInvalid(value) == 0) goto fail;
    if (Util_GlobalNodeListContainsTarget(value) != 0) goto fail;
    return 1;
fail:
    return 0;
}
