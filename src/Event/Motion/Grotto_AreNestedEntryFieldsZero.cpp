#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158AB8; symbol: Grotto_AreNestedEntryFieldsZero; size: 0x2C.
// Returns true only when the four nested entry words at offsets 8, 0x10, 0x18, and 0x20 are zero.
extern "C" int Grotto_AreNestedEntryFieldsZero(const void *p) {
    return *(const int *)((const char *)p + 8) == 0 &&
           *(const int *)((const char *)p + 0x10) == 0 &&
           *(const int *)((const char *)p + 0x18) == 0 &&
           *(const int *)((const char *)p + 0x20) == 0;
}
