#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9BDC; symbol: Math_StoreSignedQuotientAndRemainder; size: 0x30.
// Stores signed numerator divided by, and remainder modulo, the object's unsigned halfword at +0x26; the two results go to +0x28 and +0x2a.
extern "C" void Math_StoreSignedQuotientAndRemainder(void *obj, int numerator) {
    *(unsigned short *)((char *)obj + 0x28) = numerator / *(unsigned short *)((char *)obj + 0x26);
    *(unsigned short *)((char *)obj + 0x2a) = numerator % *(unsigned short *)((char *)obj + 0x26);
}
