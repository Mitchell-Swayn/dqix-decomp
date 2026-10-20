#include <globaldefs.h>
ARM
extern "C" int Memory_CompareUnsignedBytesForCount(const unsigned char *left, const unsigned char *right, int count);
// Original: arm9/ov031 @ 0x0223FB54; symbol: func_ov031_0223fb54; size: 0xC.
extern "C" int Ov031_CompareUnsignedBytesForCount(const unsigned char *left, const unsigned char *right, int count) {
    return Memory_CompareUnsignedBytesForCount(left, right, count);
}
